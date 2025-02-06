#pragma once
#include <string>
class ConsoleDisplay
{
public:
	void handleConsole();
	std::string formatTime(const std::tm& timeInfo);
};

