#pragma once
#include <opencv2/opencv.hpp>

class MotionDetector
{
public:
	MotionDetector() = default;
	virtual bool detectMotion(const cv::Mat& newFrame, cv::Mat& motionMask) = 0;
	virtual ~MotionDetector() = default;


};

