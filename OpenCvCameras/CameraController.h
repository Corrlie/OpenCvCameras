#pragma once
#include <thread>
#include <atomic>

class CameraController {
public:
    CameraController();
    void start();
    void stop();
    ~CameraController();

private:
    std::atomic<bool> running;
    std::thread cameraThread;

    void cameraLoop();
};
