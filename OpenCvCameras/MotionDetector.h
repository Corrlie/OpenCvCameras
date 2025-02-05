#pragma once
#include <opencv2/opencv.hpp>

class MotionDetector
{
public:
	MotionDetector() = default;
	bool detectMotion(const cv::Mat& newFrame, cv::Mat& motionMask);

private:
	cv::Mat prevFrame;
};

