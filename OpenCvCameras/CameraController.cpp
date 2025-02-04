#include "CameraController.h"
#include <opencv2/opencv.hpp>

CameraController::CameraController( std::unique_ptr<CameraFrameCapture> cameraFrameCapture )
    : running(true),
    cameraFrameCapture(std::move(cameraFrameCapture))
{
}

void CameraController::start()
{
    cameraThread = std::thread(&CameraController::cameraLoop, this);
}

void CameraController::stop()
{
    running = false;
    if (cameraThread.joinable()) {
        cameraThread.join();
    }
}

CameraController::~CameraController()
{
    stop();
}

void CameraController::cameraLoop()
{
    if (!cameraFrameCapture->open()) {
        std::cerr << "Error: Cannot open the camera!" << std::endl;
        return;
    }

    cv::Mat frame;
    while (running) {
        if (!cameraFrameCapture->captureFrame(frame) ||
            frame.empty()) break;
        cv::imshow("Camera Preview", frame);
        if (cv::waitKey(30) == 27) 
        { 
            running = false; 
        }
    }

    cameraFrameCapture->close();
    cv::destroyAllWindows();
}


