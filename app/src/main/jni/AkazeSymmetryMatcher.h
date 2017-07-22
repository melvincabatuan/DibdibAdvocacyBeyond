//
// Created by cobalt on 1/8/16.
//

#ifndef MHEALTH_AKAZESYMMETRYMATCHER_H
#define MHEALTH_AKAZESYMMETRYMATCHER_H

#include <opencv2/features2d.hpp>
#include <opencv2/core/mat.hpp>

namespace mhealth {

    class AkazeSymmetryMatcher {

    public:
        AkazeSymmetryMatcher();
        void apply(cv::Mat &src, cv::Mat &dst);

    private:

        /* Akaze detector and descriptor at the same time */
        cv::Ptr<cv::Feature2D> detector_descriptor;

        /* Left and Right image keypoints */
        std::vector<cv::KeyPoint> leftKeyPoints, rightKeyPoints;

        /* Keypoint Matcher */
        cv::Ptr<cv::DescriptorMatcher> descriptorMatcher;

        /* Left and Right descriptors */
        cv::Mat leftDescriptors, rightDescriptors;

        std::vector<cv::DMatch> matches;
        std::vector<cv::DMatch> bestMatches;

    };

} // namespace mhealth


#endif //MHEALTH_AKAZESYMMETRYMATCHER_H
