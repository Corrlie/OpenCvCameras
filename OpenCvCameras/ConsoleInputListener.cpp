#include "ConsoleInputListener.h"
#include <iostream>

ConsoleInputListener::ConsoleInputListener():
	exitRequested(false),
	consoleInputListenerThread(&ConsoleInputListener::listenForInput, this)
{
}

ConsoleInputListener::~ConsoleInputListener()
{
	if (consoleInputListenerThread.joinable()) {
		consoleInputListenerThread.join();
	}
}

bool ConsoleInputListener::isExitRequested()
{
	return exitRequested;
}

void ConsoleInputListener::listenForInput()
{
	std::cin.get();
	exitRequested = true;
}
