#pragma once
#include "UserInputListener.h"
#include <memory>
class ConsoleDisplay
{

public:
	//ConsoleDisplay();
	void handleConsole();
	ConsoleDisplay(std::shared_ptr<UserInputListener> inputListener);
private:
	std::shared_ptr<UserInputListener> inputListener;

};

