#include "ConsoleDisplay.h"
#include <iostream>
#include <thread>
#include <conio.h>
#include "TimeFormatter.h"
void ConsoleDisplay::handleConsole()
{
    std::cout << "Press ENTER to exit the program...\n";

    while (true) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm timeInfo;
        localtime_s(&timeInfo, &now_c);
        std::cout << "\rCurrent time: " << TimeFormatter::formatTime(timeInfo) << std::flush;

        if (_kbhit()) {
            char c = _getch();
            if (c == '\r') break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
}