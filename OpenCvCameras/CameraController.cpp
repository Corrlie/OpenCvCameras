#include "CameraController.h"
#include <opencv2/opencv.hpp>

CameraController::CameraController()
    : running(true)
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
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Cannot open the camera!" << std::endl;
        return;
    }

    cv::Mat frame;
    while (running) {
        cap >> frame;
        if (frame.empty()) break;

        cv::imshow("Camera Preview", frame);

        if (cv::waitKey(30) == 27) {
            running = false;
        }
    }

    cap.release();
    cv::destroyAllWindows();
}


