#pragma once
#include <opencv2/opencv.hpp>

class MotionContourDrawer
{
public:
	MotionContourDrawer() = delete;
	~MotionContourDrawer() = delete;
	static void handleContoursForMovingArea(cv::Mat& motionMask, cv::Mat& frame);
private:
	static void drawBoundingBoxForMovingArea(std::vector<std::vector<cv::Point>>& contours, cv::Mat& frame);
};

