#pragma once
#include <opencv2/opencv.hpp>

class CameraFrameCapture
{
public:
	virtual bool open() = 0;
	virtual bool captureFrame(cv::Mat& frame) = 0;
	virtual void close() = 0;
	virtual ~CameraFrameCapture() = default;

protected:
	cv::VideoCapture cap;
};

