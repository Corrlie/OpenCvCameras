#pragma once
#include "CameraFactory.h"
#include "WebcamCameraFrameCapture.h"
class WebcamCameraFactory :
	public CameraFactory
{
public:
	std::unique_ptr<CameraFrameCapture> createCamera() override {
		return std::make_unique<WebcamCameraFrameCapture>();
	}
};

