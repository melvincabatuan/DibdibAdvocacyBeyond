//
// Created by cobalt on 1/7/16.
//

#ifndef MHEALTH_SPIRAL_H
#define MHEALTH_SPIRAL_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <cmath>


namespace mhealth {


/* Augment a spiral guide to the user */
class Spiral {

	private:
		std::vector<cv::Point2f> trajectory;  

	public:	
		Spiral();
		Spiral(int maxRadius);
		~Spiral();

		void displayTargets(const cv::Mat &src, cv::Mat &dst, int frameCount); 
		int size();		
    };

} // namespace mhealth

#endif //MHEALTH_SPIRAL_H
