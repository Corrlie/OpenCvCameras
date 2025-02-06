#include "FrameDifferenceMotionDetector.h"

bool FrameDifferenceMotionDetector::detectMotion(const cv::Mat& newFrame, cv::Mat& motionMask)
{
	cv::Mat gray;
	cv::Mat diff;
	cv::cvtColor(newFrame, gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(gray, gray, cv::Size(15, 15), 2);

	if (prevFrame.empty()) {
		prevFrame = gray.clone();
		return false;
	}

	cv::absdiff(prevFrame, gray, diff);
	cv::threshold(diff, motionMask, 20, 255, cv::THRESH_BINARY);
	cv::dilate(motionMask, motionMask, cv::Mat::ones(17, 17, CV_8U), cv::Point(-1, -1), 3);

	prevFrame = gray.clone();

	return cv::countNonZero(motionMask) > 500;
}
