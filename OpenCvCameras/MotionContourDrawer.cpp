#include "MotionContourDrawer.h"
#include "macros.h"

void MotionContourDrawer::drawBoundingBoxForMovingArea(std::vector<std::vector<cv::Point>>& contours, cv::Mat& frame)
{
    for (const auto& contour : contours) {
        if (cv::contourArea(contour) > MIN_CONTOUR_AREA) {
            cv::Rect boundingBox = cv::boundingRect(contour);
            cv::rectangle(frame, boundingBox, 
                cv::Scalar(COLOR_CHANNEL_MIN,
                    COLOR_CHANNEL_MAX, 
                    COLOR_CHANNEL_MIN),
                CONTOUR_THICKNESS);
        }
    }
}

void MotionContourDrawer::handleContoursForMovingArea(cv::Mat& motionMask, cv::Mat& frame)
{
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(motionMask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    drawBoundingBoxForMovingArea(contours, frame);
}



