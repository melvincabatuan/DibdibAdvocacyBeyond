//
// Created by cobalt on 1/7/16.
//

#include "OrbSymmetryMatcher.h"

using namespace mhealth;

OrbSymmetryMatcher::OrbSymmetryMatcher(){
    detector_descriptor = cv::ORB::create();
    descriptorMatcher = cv::DescriptorMatcher::create(
                    "BruteForce-Hamming");
}



void OrbSymmetryMatcher::apply(cv::Mat &srcGray, cv::Mat &dst) {

    // clear points
    leftKeyPoints.clear();
    rightKeyPoints.clear();

    try {

        detector_descriptor->detectAndCompute(srcGray.colRange(0, srcGray.cols / 2), cv::Mat(),
                                              leftKeyPoints, leftDescriptors, false);
        detector_descriptor->detectAndCompute(srcGray.colRange(srcGray.cols / 2, srcGray.cols),
                                              cv::Mat(), rightKeyPoints, rightDescriptors, false);

        if(leftKeyPoints.size() < 1 || rightKeyPoints.size() < 1 ) return;

        matches.clear();

        descriptorMatcher->match(leftDescriptors, rightDescriptors, matches, cv::Mat());


        //Select the best matching points and draw them
        float min_dist = 100;
        for( int i = 0; i < leftDescriptors.rows; i++ )
        {
            float dist = matches[i].distance;
            if( dist < min_dist ) min_dist = dist;
        }

        bestMatches.clear();
        for( int i = 0; i < leftDescriptors.rows; i++ )
        {
            if( matches[i].distance <= 3 * min_dist )
            {
                bestMatches.push_back( matches[i]);
            }
        }


        cv::drawMatches(srcGray.colRange(0, srcGray.cols / 2), leftKeyPoints,
                        srcGray.colRange(srcGray.cols / 2, srcGray.cols), rightKeyPoints,
                        bestMatches, dst);

    } catch (cv::Exception& e){
      // LOGD(LOG_TAG, e.msg.c_str());
    }

}
