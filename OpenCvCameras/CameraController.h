#pragma once
#include <thread>
#include <atomic>
#include "CameraFrameCapture.h"
#include "MotionDetector.h"

class CameraController {
public:
    CameraController( std::unique_ptr<CameraFrameCapture> cameraFrameCapture,
        std::shared_ptr<MotionDetector> motionDetector);
    void start();
    void stop();
    ~CameraController();

private:
    std::atomic<bool> running;
    std::thread cameraThread;
    std::unique_ptr<CameraFrameCapture> cameraFrameCapture;
    std::shared_ptr<MotionDetector> motionDetector;

    void cameraLoop();
};
