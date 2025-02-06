#pragma once
#include "Logger.h"
class FileLogger :
    public Logger
{
public:
    void log() override;
};

