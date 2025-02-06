#include "ConsoleDisplay.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <thread>
void ConsoleDisplay::handleConsole()
{
    std::cout << "Press ENTER to exit the program...\n";

    while (true) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm timeInfo;
        localtime_s(&timeInfo, &now_c);
        std::cout << "\rCurrent time: " << formatTime(timeInfo) << std::flush;

        if (std::cin.rdbuf()->in_avail() > 0) {
            std::cin.get();
            break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
}

std::string ConsoleDisplay::formatTime(const std::tm& timeInfo)
{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << timeInfo.tm_hour << ":"
        << std::setw(2) << std::setfill('0') << timeInfo.tm_min << ":"
        << std::setw(2) << std::setfill('0') << timeInfo.tm_sec;
    return oss.str();
}
