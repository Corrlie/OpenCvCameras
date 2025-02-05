#pragma once
#include <thread>
#include <atomic>
#include "CameraFrameCapture.h"
#include "MotionDetector.h"

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
    MotionDetector motionDetector;

    void cameraLoop();
    void HandleContoursForMovingArea(cv::Mat& motionMask, cv::Mat& frame);
    void drawBoundingBoxForMovingArea(std::vector<std::vector<cv::Point>>& contours, cv::Mat& frame);
};
