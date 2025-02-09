#include "ConsoleDisplay.h"
#include <iostream>
#include <thread>
#include <conio.h>
#include "TimeFormatter.h"
void ConsoleDisplay::handleConsole()
{
    std::cout << "Press ENTER to exit the program...\n";

    while (true) {
        if (inputListener->isExitRequested()) {
            break;
        }
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm timeInfo;
        localtime_s(&timeInfo, &now_c);
        std::cout << "\rCurrent time: " << TimeFormatter::formatTime(timeInfo) << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

ConsoleDisplay::ConsoleDisplay(std::shared_ptr<UserInputListener> inputListener):
    inputListener(inputListener)
{
}

