#include "Client.h"
#include <iostream>
#include <thread>
#include <conio.h>

using namespace std;

Client::Client()
{
    ConnectToServer();
}

void Client::init()
{
    StartClientLoop();
    Disconnect();
}

void Client::ConnectToServer()
{
    // Client
    client = enet_host_create(NULL /* create a client host */,
        1 /* only allow 1 outgoing connection */,
        2 /* allow up 2 channels to be used, 0 and 1 */,
        0 /* assume any amount of incoming bandwidth */,
        0 /* assume any amount of outgoing bandwidth */);

    cout << "Please enter a username" << endl;
    cin >> username;

    enet_address_set_host(&address, "localhost");
    address.port = 1234;
    /* Initiate the connection, allocating the two channels 0 and 1. */
    peer = enet_host_connect(client, &address, 2, 0);

    if (enet_host_service(client, &event, 5000) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        cout << "Connection to localhost:1234 succeeded." << endl;
    }
    else
    {
        /* Either the 5 seconds are up or a disconnect event was */
        /* received. Reset the peer in the event the 5 seconds   */
        /* had run out without any significant event.            */
        //enet_host_broadcast(host, 0, packet);
        enet_peer_reset(peer);
        cout << "Connection to localhost:1234 failed." << endl;
    }
}

void Client::StartClientLoop()
{
    while (true)
    {
        ENetEvent event;
        while (enet_host_service(client, &event, 1000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_RECEIVE:
                cout << (char*)event.packet->data << endl;

                enet_packet_destroy(event.packet);
            }
        }
    }
}

void Client::Disconnect() 
{
    ENetEvent event;
    enet_peer_disconnect(peer, 0);

    /* Allow up to 3 seconds for the disconnect to succeed
     * and drop any packets received packets.
     */
    while (enet_host_service(client, &event, 3000) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_RECEIVE:
            enet_packet_destroy(event.packet);
            break;
        case ENET_EVENT_TYPE_DISCONNECT:
            cout << "Disconnection succeeded." << endl;
            return;
        }
    }

    /* We've arrived here, so the disconnect attempt didn't */
    /* succeed yet.  Force the connection down.             */
    enet_peer_reset(peer);
}

void Client::SendOurMessage(std::string message)
{
    string modifiedMessage = username + ": " + message;
    ENetPacket* packet = enet_packet_create(modifiedMessage.c_str(),
        strlen(modifiedMessage.c_str()) + 1,
        ENET_PACKET_FLAG_RELIABLE);
    /* Send the packet to the peer over channel id 0. */
    /* One could also broadcast the packet by         */
    enet_host_broadcast(client, 0, packet);

    enet_host_flush(client);
}

void Client::HandleInput()
{
    string currentMessage = "";
    while (true)
    {
        if (_kbhit())
        {
            int input = _getch();

            if (input == '\r')
            {
                if (currentMessage.length() != 0)
                {
                    SendOurMessage(currentMessage);
                    currentMessage = "";
                    cin.clear();
                    cin.ignore(1000000000, '\n');
                }
            }
            else
            {
                currentMessage += (char)input;
            }
        }
    }
}
