#pragma once
#include <enet/enet.h>
#include <string>

class Server
{
	ENetAddress address;
	ENetHost* server;
	std::string username;

	public:
		Server();
		void init();
		void CreateServer();
		void StartServerLoop();
		void KillServer();
		void SendWelcomeMessage();
		void SendOurMessage(std::string message);
		void HandleInput();
};