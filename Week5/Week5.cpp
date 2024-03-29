#include <enet/enet.h>
#include <iostream>
#include "BeeHiveSimulation.h"

#include "Client.h"
#include "Server.h"

using namespace std;

// server
ENetAddress address;
ENetHost* server;
ENetHost* client;

string username;

bool CreateServer();
bool CreateClient();
void NetworkingProject();
void StartBeeHive();
void ChatRoom();

int main(int argc, char** argv)
{
    //StartBeeHive();
    //NetworkingProject();
    ChatRoom();
}

void ChatRoom()
{
    cout << "1) Create Sever" << endl;
    cout << "2) Create Client" << endl;
    int type;
    cin >> type;
    if (type == 1)
    {
        Server server;
        server.init();
    }
    else if(type == 2)
    {
        Client client;
        client.init();
    }
}

void NetworkingProject()
{
    // init
    if (enet_initialize() != 0)
    {
        cerr << "An error occurred while initializing ENet." << endl;
        return;
    }
    atexit(enet_deinitialize);

    cout << "1) Create Sever" << endl;
    cout << "2) Create Client" << endl;
    int UserInput;
    cin >> UserInput;

    if (UserInput == 1)
    {
        if (!CreateServer())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet server host.\n");
            exit(EXIT_FAILURE);
        }

        while (true)
        {
            ENetEvent event;
            /* Wait up to 1000 milliseconds for an event. */
            while (enet_host_service(server, &event, 1000) > 0)
            {
                switch (event.type)
                {
                case ENET_EVENT_TYPE_CONNECT:
                    printf("A new client connected from %x:%u.\n",
                        event.peer->address.host,
                        event.peer->address.port);
                    /* Store any relevant client information here. */
                    event.peer->data = (void*)"Client information";

                    {
                        string welcomeMessage = "Welcome";

                        ENetPacket* packet = enet_packet_create(welcomeMessage.c_str(),
                            strlen(welcomeMessage.c_str()) + 1,
                            ENET_PACKET_FLAG_RELIABLE);
                        /* Send the packet to the peer over channel id 0. */
                        /* One could also broadcast the packet by         */
                        //enet_host_broadcast (server, 0, packet);
                        enet_peer_send(event.peer, 0, packet);

                        /* One could just use enet_host_service() instead. */
                        enet_host_flush(server);
                    }


                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    cout << event.packet->data << endl;
                    /* Clean up the packet now that we're done using it. */
                    enet_packet_destroy(event.packet);
                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    printf("%s disconnected.\n", (char*)event.peer->data);
                    /* Reset the peer's client information. */
                    event.peer->data = NULL;
                }
            }
        }
    }
    else if (UserInput == 2)
    {
        if (!CreateClient())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet client host.\n");
            exit(EXIT_FAILURE);
        }

        ENetAddress address;
        ENetEvent event;
        ENetPeer* peer;
        /* Connect to some.server.net:1234. */
        enet_address_set_host(&address, "localhost");
        address.port = 1234;
        /* Initiate the connection, allocating the two channels 0 and 1. */
        peer = enet_host_connect(client, &address, 2, 0);
        if (peer == NULL)
        {
            fprintf(stderr,
                "No available peers for initiating an ENet connection.\n");
            exit(EXIT_FAILURE);
        }
        /* Wait up to 5 seconds for the connection attempt to succeed. */
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
    else
    {
        cout << "Invalid Input" << endl;
    }

    if (server != nullptr)
    {
        enet_host_destroy(server);

    }
    if (client != nullptr)
    {
        enet_host_destroy(client);
    }
}

string getInput()
{
    string response;
    cin >> response;
    return response;
}

bool CreateServer()
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

    return server != nullptr;
}

bool CreateClient()
{
    // Client
    client = enet_host_create(NULL /* create a client host */,
        1 /* only allow 1 outgoing connection */,
        2 /* allow up 2 channels to be used, 0 and 1 */,
        0 /* assume any amount of incoming bandwidth */,
        0 /* assume any amount of outgoing bandwidth */);

    cout << "Please enter a username" << endl;
    cin >> username;

    return client != nullptr;
}

void StartBeeHive()
{
    BeeHiveSimulation *sim = new BeeHiveSimulation(3,1);
    sim->init();
}