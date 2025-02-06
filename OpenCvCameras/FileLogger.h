#pragma once
#include "Logger.h"
#include <string>
#include <fstream>
#include <mutex>
class FileLogger :
    public Logger
{
public:
    FileLogger(const std::string& filename);
    void log() override;
    ~FileLogger();

private:
    std::ofstream logFile;
    std::mutex logMutex;
};

