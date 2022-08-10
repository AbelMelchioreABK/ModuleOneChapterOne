#include "Server.h"
#include <iostream>
#include <thread>
#include <conio.h>


using namespace std;

Server::Server()
{
    CreateServer();
}

void Server::init()
{
    StartServerLoop();
    KillServer();
}

void Server::CreateServer()
{

    /* Bind the server to the default localhost.     */
    /* A specific host address can be specified by   */
    /* enet_address_set_host (& address, "x.x.x.x"); */
    address.host = ENET_HOST_ANY;
    /* Bind the server to port 1234. */
    address.port = 1234;
    server = enet_host_create(&address /* the address to bind the server host to */,
        32      /* allow up to 32 clients and/or outgoing connections */,
        2      /* allow up to 2 channels to be used, 0 and 1 */,
        0      /* assume any amount of incoming bandwidth */,
        0      /* assume any amount of outgoing bandwidth */);

    username = "Server";
}

void Server::StartServerLoop()
{
    while (true)
    {
        ENetEvent event;
        /* Wait up to 1000 milliseconds for an event. */
        while (enet_host_service(server, &event, 1000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                /* Store any relevant client information here. */
                event.peer->data = (void*)"Client information";

                SendWelcomeMessage();

                break;
            case ENET_EVENT_TYPE_RECEIVE:
                cout << event.packet->data << endl;
                /* Clean up the packet now that we're done using it. */
                enet_packet_destroy(event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                event.peer->data = NULL;
            }
        }
    }
}

void Server::KillServer()
{
    enet_host_destroy(server);
}

void Server::SendWelcomeMessage()
{
    SendOurMessage("Welcome");
}

void Server::SendOurMessage(string message)
{
    string modifiedMessage = username + ": " + message;
    ENetPacket* packet = enet_packet_create(modifiedMessage.c_str(),
        strlen(modifiedMessage.c_str()) + 1,
        ENET_PACKET_FLAG_RELIABLE);
    /* Send the packet to the peer over channel id 0. */
    /* One could also broadcast the packet by         */
    enet_host_broadcast(server, 0, packet);

    enet_host_flush(server);
}

void Server::HandleInput()
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