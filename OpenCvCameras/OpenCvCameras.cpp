#include <iostream>
#include <opencv2/core/utils/logger.hpp>
#include "CameraController.h"
#include "WebcamCameraFrameCapture.h"
#include "FrameDifferenceMotionDetector.h"
#include "FileLogger.h"
#include "ConsoleDisplay.h"
#include "WebcamCameraFactory.h"
#include "ConsoleInputListener.h"

int main() {
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);

    ConsoleDisplay display(std::make_shared<ConsoleInputListener>());
    std::shared_ptr<Logger> fileLogger = std::make_shared<FileLogger>("fileLogs.txt");
    std::shared_ptr<MotionDetector> detector = std::make_shared<FrameDifferenceMotionDetector>(fileLogger);
    WebcamCameraFactory webcamFactory;
    CameraController cameraController(webcamFactory.createCamera(), detector);

    cameraController.start();
    display.handleConsole();
    cameraController.stop();

    std::cout << "\nProgram terminated successfully." << std::endl;
    return 0;
}
