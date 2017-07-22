#pragma once

#include "kcf_src/kcftracker.hpp"
#include "TraceQueue.hpp"

#ifndef KCF_TRACKER_H
#define KCF_TRACKER_H

class KCF
{
	public:
    	KCF(); 
    	~KCF();
    	bool initialize(cv::Mat &im_gray, long topLeftx, long topLefty, long width, long height);   
		bool isInitialized();
		bool processFrame(cv::Mat &im_gray, cv::Mat &im_rgba);
		
	private:
	    //bool HOG = true;
		//bool FIXEDWINDOW = true;
		//bool MULTISCALE = true;
		//bool LAB = true;
		KCFTracker tracker;
		bool isInit;
		mhealth::TraceQueue Trace;
};

#endif // CUSTOM_TRACKER_H
