//
// Created by cobalt on 1/7/16.
//

#ifndef MHEALTH_SYMMETRYMATCHER_H
#define MHEALTH_SYMMETRYMATCHER_H

#include <opencv2/features2d.hpp>
#include <opencv2/core/mat.hpp>

namespace mhealth {

    class OrbSymmetryMatcher {

    public:
        OrbSymmetryMatcher();
        void apply(cv::Mat &src, cv::Mat &dst);

    private:

        /* ORB detector and descriptor at the same time */
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

#endif //MHEALTH_SYMMETRYMATCHER_H