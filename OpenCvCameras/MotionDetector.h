#pragma once
#include <opencv2/opencv.hpp>
#include "Logger.h"

class MotionDetector
{
public:
	virtual bool detectMotion(const cv::Mat& newFrame, cv::Mat& motionMask) = 0;
	virtual ~MotionDetector() = default;

};

