#pragma once
#include <thread>
#include <atomic>
#include "CameraFrameCapture.h"

class CameraController {
public:
    CameraController( std::unique_ptr<CameraFrameCapture> cameraFrameCapture );
    void start();
    void stop();
    ~CameraController();

private:
    std::atomic<bool> running;
    std::thread cameraThread;
    std::unique_ptr<CameraFrameCapture> cameraFrameCapture;

    void cameraLoop();
};
