#include "SmashKidsServer.hpp"
#include <iostream>
#include <string>

#define PORT 9000

#define MAX_WORKER_COUNT 16

#define MAX_CLIENT 1024

int main()
{
	
	SmashKidsServer smashKidsServer;
	smashKidsServer.Init(PORT, MAX_WORKER_COUNT);
	smashKidsServer.BindAndListen();
	smashKidsServer.Run(MAX_CLIENT);

	// Blocking for main thread termination
	std::string input;
	while (std::cin >> input)
	{
		if (input == "quit")
		{
			std::cout << "Stopping server...\n";
			break;
		}

		std::cout << "Unknown command. Type 'quit' to terminate.\n";
	}

	smashKidsServer.End();

	
	std::cout << "Server Terminated. Type any word to quit\n";
	std::cin >> input;

	std::cin.get();
	return 0;
}