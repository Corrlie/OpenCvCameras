#include "WebcamCameraFrameCapture.h"

bool WebcamCameraFrameCapture::open()
{
    cap.open(0);
    return cap.isOpened();
}

bool WebcamCameraFrameCapture::captureFrame(cv::Mat& frame)
{
    return cap.read(frame);
}

void WebcamCameraFrameCapture::close()
{
    cap.release();
}
