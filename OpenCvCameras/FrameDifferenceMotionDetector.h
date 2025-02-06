#pragma once
#include "MotionDetector.h"
class FrameDifferenceMotionDetector :
    public MotionDetector
{
public:
    FrameDifferenceMotionDetector(std::shared_ptr<Logger> logger);
    bool detectMotion(const cv::Mat& newFrame, cv::Mat& motionMask) override;
private:
    cv::Mat prevFrame;
    std::shared_ptr<Logger> logger;
};

