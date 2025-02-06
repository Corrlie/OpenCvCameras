#pragma once
#include "CameraFrameCapture.h"
class CameraFactory
{
public:
	virtual std::unique_ptr<CameraFrameCapture> createCamera() = 0;
	virtual ~CameraFactory() = default;
};

