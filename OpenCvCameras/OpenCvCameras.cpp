#include <iostream>
#include "CameraController.h"

int main() {
    CameraController cameraController;
    cameraController.start();

    std::cout << "Press Enter to exit the program..." << std::endl;
    std::cin.get();
    cameraController.stop();

    std::cout << "Program terminated successfully." << std::endl;
    return 0;
}
