# Motion Detection with Multithreading in C++ and OpenCV

## Overview

This project implements a motion detection system using C++ and OpenCV, utilizing multithreading to efficiently separate concerns. The system detects motion from a camera, logs detected events, and displays the current time.

## Features

- Multithreading: Efficient processing of motion detection, logging, and console display.

- Motion Detection: Uses OpenCV to process camera frames and detect motion.

- Logging System: Records motion detection events.

- Console Display: The main thread continuously displays the current time.

- Extensibility: The project is designed using design patterns like Strategy and Factory, allowing for easy expansion:

    - Support for different types of cameras beyond the built-in webcam.

    - Integration of alternative motion detection algorithms.

    - Flexible logging mechanisms (e.g., file-based, database, cloud storage).

## Future Enhancements

- Support for additional cameras (IP cameras, RTSP streams, etc.).

- More advanced motion detection algorithms.

- Enhanced logging (e.g., log files, remote database storage).

- GUI integration for real-time visualization.