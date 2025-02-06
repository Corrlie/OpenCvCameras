#include "CameraController.h"
#include "MotionContourDrawer.h"
#include <opencv2/opencv.hpp>

CameraController::CameraController( std::unique_ptr<CameraFrameCapture> cameraFrameCapture,
    std::shared_ptr<MotionDetector> motionDetector )
    : running(true),
    cameraFrameCapture(std::move(cameraFrameCapture) ),
    motionDetector(std::move(motionDetector) ) 
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
    cv::Mat motionMask;

    while (running) {
        if (cameraFrameCapture->captureFrame(frame) &&
            !frame.empty()) 
        {
            if(motionDetector->detectMotion(frame, motionMask))
            {
                MotionContourDrawer::handleContoursForMovingArea(motionMask, frame);
            }
        }
        else 
        {
            break;
        }

        cv::imshow("Camera Preview", frame);
        if(!motionMask.empty()) cv::imshow("Motion Mask", motionMask);
        if (cv::waitKey(30) == 27) 
        { 
            running = false; 
        }
    }

    cameraFrameCapture->close();
    cv::destroyAllWindows();
}


