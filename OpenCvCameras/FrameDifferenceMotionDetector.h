#pragma once
#include "MotionDetector.h"
class FrameDifferenceMotionDetector :
    public MotionDetector
{
public:
    bool detectMotion(const cv::Mat& newFrame, cv::Mat& motionMask) override;
private:
    cv::Mat prevFrame;
};

