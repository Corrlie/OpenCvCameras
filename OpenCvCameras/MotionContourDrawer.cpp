#include "MotionContourDrawer.h"

void MotionContourDrawer::drawBoundingBoxForMovingArea(std::vector<std::vector<cv::Point>>& contours, cv::Mat& frame)
{
    for (const auto& contour : contours) {
        if (cv::contourArea(contour) > 500) {
            cv::Rect boundingBox = cv::boundingRect(contour);
            cv::rectangle(frame, boundingBox, cv::Scalar(0, 255, 0), 2);
        }
    }
}

void MotionContourDrawer::handleContoursForMovingArea(cv::Mat& motionMask, cv::Mat& frame)
{
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(motionMask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    drawBoundingBoxForMovingArea(contours, frame);
}



