#include "FileLogger.h"
#include <chrono>
#include <iomanip>

FileLogger::FileLogger(const std::string& filename)
{
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        //TODO: errors handling - error: cannot open file
    }
}

void FileLogger::log()
{
    std::lock_guard<std::mutex> lock(logMutex);
    auto now = std::chrono::system_clock::now();
    std::tm timeStruct;
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    localtime_s(&timeStruct, &time);

    logFile << "[" << std::put_time(&timeStruct, "%Y-%m-%d %H:%M:%S") << "] " << "Detected movement!" << std::endl;
}

FileLogger::~FileLogger()
{
    if (logFile.is_open()) {
        logFile.close();
    }
}
