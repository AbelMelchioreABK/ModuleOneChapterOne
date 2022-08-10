#pragma once
#include <enet/enet.h>
#include <string>

class Client
{
	ENetAddress address;
	ENetHost* client;
	ENetEvent event;
	ENetPeer* peer;
	std::string username;

	public:
		Client();
		void init();
		void ConnectToServer();
		void StartClientLoop();
		void Disconnect();
		void SendOurMessage(std::string message);
		void HandleInput();
};