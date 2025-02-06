#include <iostream>
#include "CameraController.h"
#include "WebcamCameraFrameCapture.h"
#include "FrameDifferenceMotionDetector.h"

int main() {
 
    CameraController cameraController(std::make_unique<WebcamCameraFrameCapture>(), 
        std::make_shared<FrameDifferenceMotionDetector>());
    cameraController.start();

    std::cout << "Press Enter to exit the program..." << std::endl;
    std::cin.get();
    cameraController.stop();

    std::cout << "Program terminated successfully." << std::endl;
    return 0;
}
