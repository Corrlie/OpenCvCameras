#pragma once
#include "UserInputListener.h"
#include <thread>
#include <atomic>
class ConsoleInputListener :
    public UserInputListener
{
public:
    ConsoleInputListener();
    ~ConsoleInputListener();
    bool isExitRequested() override;
private:
    std::atomic<bool> exitRequested;
    std::thread consoleInputListenerThread;
    void listenForInput();
};

