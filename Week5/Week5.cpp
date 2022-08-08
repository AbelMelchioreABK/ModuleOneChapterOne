#include <enet/enet.h>
#include <iostream>
#include "BeeHiveSimulation.h"

using namespace std;

// server
ENetAddress address;
ENetHost* server;
ENetHost* client;



bool CreateServer();
bool CreateClient();
void NetworkingProject();
void StartBeeHive();

int main(int argc, char** argv)
{
    StartBeeHive();
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
    }
    else if (UserInput == 2)
    {
        if (!CreateClient())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet client host.\n");
            exit(EXIT_FAILURE);
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
    return client != nullptr;
}

// This just vomits you into an other file
void StartBeeHive()
{
    BeeHiveSimulation *sim = new BeeHiveSimulation(3,1);
    sim->init();
}