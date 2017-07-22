#include "KCF.h"


KCF::KCF(){
    isInit = false;    
};

KCF::~KCF(){};


bool KCF::initialize(cv::Mat &src, long topLeftx, long topLefty, long width, long height){
	cv::Rect roi = cv::Rect(topLeftx, topLefty, width, height);
	cv::Mat bgr;
	cv::cvtColor(src, bgr, CV_BGRA2BGR);
	tracker.init(roi, bgr);
	isInit = true;
	return isInit;
}

bool KCF::isInitialized(){
	return isInit;
}

bool KCF::processFrame(cv::Mat &src, cv::Mat &im_rgba){

	cv::Rect boundingBox;
	cv::Mat bgr;
	cv::cvtColor(src, bgr, CV_BGRA2BGR);
	boundingBox = tracker.update(bgr);

    int Center_x, Center_y;
    Center_x = boundingBox.x + boundingBox.height / 2;
    Center_y = boundingBox.y + boundingBox.width / 2;
    int Center[2] = {Center_x, Center_y};
    Trace.append(Center);

    rectangle(im_rgba, boundingBox, cv::Scalar( 255, 0, 0 ), 3, 8, 0);
    Trace.draw_trace(im_rgba);
}
