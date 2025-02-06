#include "CameraController.h"
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
                HandleContoursForMovingArea(motionMask, frame);
            }
        }
        else 
        {
            break;
        }

        cv::imshow("Camera Preview", frame);
        if(!motionMask.empty()) cv::imshow("Motion Mask", motionMask);
        //cv::imshow("Motion Mask", motionMask);
        if (cv::waitKey(30) == 27) 
        { 
            running = false; 
        }
    }

    cameraFrameCapture->close();
    cv::destroyAllWindows();
}

void CameraController::HandleContoursForMovingArea(cv::Mat& motionMask, cv::Mat& frame)
{
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(motionMask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    drawBoundingBoxForMovingArea(contours, frame);
}

void CameraController::drawBoundingBoxForMovingArea(std::vector<std::vector<cv::Point>>& contours, cv::Mat& frame)
{
    for (const auto& contour : contours) {
        if (cv::contourArea(contour) > 500) {
            cv::Rect boundingBox = cv::boundingRect(contour);
            cv::rectangle(frame, boundingBox, cv::Scalar(0, 255, 0), 2);
        }
    }
}


