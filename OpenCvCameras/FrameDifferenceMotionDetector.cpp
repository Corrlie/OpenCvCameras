#include "FrameDifferenceMotionDetector.h"
#include "macros.h"

FrameDifferenceMotionDetector::FrameDifferenceMotionDetector(std::shared_ptr<Logger> logger):
	logger(std::move(logger))
{
}

bool FrameDifferenceMotionDetector::detectMotion(const cv::Mat& newFrame, cv::Mat& motionMask)
{
	cv::Mat gray;
	cv::Mat diff;
	cv::cvtColor(newFrame, gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(gray, gray, 
		cv::Size(GAUSSIAN_BLUR_KERNEL_SIZE, GAUSSIAN_BLUR_KERNEL_SIZE),
		GAUSSIAN_BLUR_SIGMA_X);

	if (prevFrame.empty()) {
		prevFrame = gray.clone();
		return false;
	}

	cv::absdiff(prevFrame, gray, diff);
	cv::threshold(diff, motionMask, 
		BINARY_THRESHOLD_VALUE, BINARY_THRESHOLD_MAX, cv::THRESH_BINARY);

	cv::dilate(motionMask, motionMask, 
		cv::Mat::ones(DILATE_KERNEL_SIZE,
			DILATE_KERNEL_SIZE, CV_8U),
			cv::Point(DILATE_ANCHOR, DILATE_ANCHOR), DILATE_ITERATIONS);

	prevFrame = gray.clone();

	bool moveDetected{ cv::countNonZero(motionMask) > MOTION_DETECTION_THRESHOLD };

	if (moveDetected) {
		logger->log();
	}
	return moveDetected;
}
