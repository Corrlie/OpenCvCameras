#pragma once
#include "CameraFrameCapture.h"
class WebcamCameraFrameCapture :
    public CameraFrameCapture
{
	virtual bool open() override;
	virtual bool captureFrame(cv::Mat& frame) override;
	virtual void close() override;
};

