#ifndef MHEALTH_DETECTIONBASEDTRACKER_H
#define MHEALTH_DETECTIONBASEDTRACKER_H


#include <jni.h>
#include <android/log.h>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>


#define LOG_TAG "MHEALTH_DETECTIONBASEDTRACKER"
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))


namespace mhealth {

    inline void vector_Rect_to_Mat(std::vector<cv::Rect>& v_rect, cv::Mat& mat);

    class CascadeDetectorAdapter: public cv::DetectionBasedTracker::IDetector
    {
    public:
        CascadeDetectorAdapter(cv::Ptr<cv::CascadeClassifier> detector):
                IDetector(),
                Detector(detector)
        {
            LOGD("CascadeDetectorAdapter::Detect::Detect");
            CV_Assert(detector);
        }

        void detect(const cv::Mat &Image, std::vector<cv::Rect> &objects)
        {
            LOGD("CascadeDetectorAdapter::Detect: begin");
            LOGD("CascadeDetectorAdapter::Detect: scaleFactor=%.2f, minNeighbours=%d, minObjSize=(%dx%d), maxObjSize=(%dx%d)", scaleFactor, minNeighbours, minObjSize.width, minObjSize.height, maxObjSize.width, maxObjSize.height);
            Detector->detectMultiScale(Image, objects, scaleFactor, minNeighbours, 0, minObjSize, maxObjSize);
            LOGD("CascadeDetectorAdapter::Detect: end");
        }

        virtual ~CascadeDetectorAdapter()
        {
            LOGD("CascadeDetectorAdapter::Detect::~Detect");
        }

    private:
        CascadeDetectorAdapter();
        cv::Ptr<cv::CascadeClassifier> Detector;
    };

    struct DetectorAgregator
    {
        cv::Ptr<CascadeDetectorAdapter> mainDetector;
        cv::Ptr<CascadeDetectorAdapter> trackingDetector;

        cv::Ptr<cv::DetectionBasedTracker> tracker;
        DetectorAgregator(cv::Ptr<CascadeDetectorAdapter>& _mainDetector, cv::Ptr<CascadeDetectorAdapter>& _trackingDetector):
                mainDetector(_mainDetector),
                trackingDetector(_trackingDetector)
        {
            CV_Assert(_mainDetector);
            CV_Assert(_trackingDetector);

            cv::DetectionBasedTracker::Parameters DetectorParams;
            tracker = cv::makePtr<cv::DetectionBasedTracker>(mainDetector, trackingDetector, DetectorParams);
        }
    };
} // namespace mhealth


#endif // MHEALTH_DETECTIONBASEDTRACKER_H
