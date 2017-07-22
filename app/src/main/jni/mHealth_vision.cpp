//
// Created by cobalt on 1/4/16.
// mHealth JNI
//

#include <jni.h>
#include <opencv2/core.hpp>


#include "DetectionBasedTracker.h"

/* Matchers */
#include "OrbSymmetryMatcher.h"
#include "AkazeSymmetryMatcher.h"
#include "BriskSymmetryMatcher.h"

/* Trackers */
#include "KCF.h" 

/* Pattern*/
#include "Spiral.h"


using namespace mhealth;


#ifdef __cplusplus
extern "C" {
#endif



/****************************** Spiral Pattern ******************************/


JNIEXPORT jlong JNICALL
Java_ph_edu_dlsu_mhealth_vision_Spiral_nativeCreateObject(JNIEnv *env, jclass type, jint maxRadius) {

    Spiral *self = new Spiral(maxRadius);
    return (jlong) self;
}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_Spiral_nativeDestroyObject(JNIEnv *env, jclass type,
                                                                         jlong thiz) 
{

    if (thiz != 0) {
        Spiral *self = (Spiral *) thiz;
        delete self;
    }

}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_Spiral_apply__JJJI(JNIEnv *env, jclass type,
                                                                jlong thiz, jlong srcAddr,
                                                                jlong dstAddr, jint counter) {

    if (thiz != 0) {
        Spiral *self = (Spiral *) thiz;
        cv::Mat &src = *(cv::Mat *) srcAddr;
        cv::Mat &dst = *(cv::Mat *) dstAddr;
        
        
        self->displayTargets(src, dst, counter);
    }

}




/***********************************    KCF Tracker   ************************************/

JNIEXPORT jlong JNICALL
Java_ph_edu_dlsu_mhealth_vision_KCF_nativeCreateObject(JNIEnv *env, jclass type) {

    KCF *self = new KCF();
    return (jlong) self;

}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_KCF_nativeDestroyObject(JNIEnv *env,
                                                                             jclass type,
                                                                             jlong thiz) {

    if (thiz != 0) {
        KCF *self = (KCF *) thiz;
        delete self;
    }

}

JNIEXPORT jboolean JNICALL
Java_ph_edu_dlsu_mhealth_vision_KCF_initialize__JJJJJJ(JNIEnv *env,
                                                                            jclass type, jlong thiz,
                                                                            jlong srcAddr,
                                                                            jlong xTopLeft,
                                                                            jlong yTopLeft,
                                                                            jlong width,
                                                                            jlong height) {

    KCF *self = (KCF *) thiz;
    cv::Mat& im_src  = *(cv::Mat*)srcAddr;
    return self->initialize(im_src, xTopLeft, yTopLeft, width, height);

}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_KCF_apply__JJJ(JNIEnv *env, jclass type,
                                                                    jlong thiz, jlong srcAddr,
                                                                    jlong dstAddr) {

    KCF *self = (KCF *) thiz;

    if (!(self->isInitialized()))
        return;

    cv::Mat& im_gray  = *(cv::Mat*)srcAddr;
    cv::Mat& im_rgba  = *(cv::Mat*)dstAddr;

    self->processFrame(im_gray, im_rgba);

}







/****************************** BriskSymmetryMatcher ******************************/


JNIEXPORT jlong JNICALL
Java_ph_edu_dlsu_mhealth_vision_BriskSymmetryMatcher_nativeCreateObject(JNIEnv *env, jclass type) {

    BriskSymmetryMatcher *self = new BriskSymmetryMatcher();
    return (jlong) self;
}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_BriskSymmetryMatcher_nativeDestroyObject(JNIEnv *env, jclass type,
                                                                         jlong thiz) {

    if (thiz != 0) {
        BriskSymmetryMatcher *self = (BriskSymmetryMatcher *) thiz;
        delete self;
    }

}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_BriskSymmetryMatcher_apply__JJJ(JNIEnv *env, jclass type,
                                                                jlong thiz, jlong srcAddr,
                                                                jlong dstAddr) {

    if (thiz != 0) {
        BriskSymmetryMatcher *self = (BriskSymmetryMatcher *) thiz;
        cv::Mat &src = *(cv::Mat *) srcAddr;
        cv::Mat &dst = *(cv::Mat *) dstAddr;
        self->apply(src, dst);
    }

}






/****************************** AkazeSymmetryMatcher ******************************/

JNIEXPORT jlong JNICALL
Java_ph_edu_dlsu_mhealth_vision_AkazeSymmetryMatcher_nativeCreateObject(JNIEnv *env, jclass type) {

    AkazeSymmetryMatcher *self = new AkazeSymmetryMatcher();
    return (jlong) self;
}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_AkazeSymmetryMatcher_nativeDestroyObject(JNIEnv *env, jclass type,
                                                                         jlong thiz) {

    if (thiz != 0) {
        AkazeSymmetryMatcher *self = (AkazeSymmetryMatcher *) thiz;
        delete self;
    }

}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_AkazeSymmetryMatcher_apply__JJJ(JNIEnv *env, jclass type,
                                                                jlong thiz, jlong srcAddr,
                                                                jlong dstAddr) {

    if (thiz != 0) {
        AkazeSymmetryMatcher *self = (AkazeSymmetryMatcher *) thiz;
        cv::Mat &src = *(cv::Mat *) srcAddr;
        cv::Mat &dst = *(cv::Mat *) dstAddr;
        self->apply(src, dst);
    }

}










/****************************** OrbSymmetryMatcher ******************************/


JNIEXPORT jlong JNICALL
Java_ph_edu_dlsu_mhealth_vision_OrbSymmetryMatcher_nativeCreateObject(JNIEnv *env, jclass type) {

    OrbSymmetryMatcher *self = new OrbSymmetryMatcher();
    return (jlong) self;

}

JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_OrbSymmetryMatcher_nativeDestroyObject(JNIEnv *env, jclass type,
                                                                       jlong thiz) {

    if (thiz != 0) {
        OrbSymmetryMatcher *self = (OrbSymmetryMatcher *) thiz;
        delete self;
    }

}


JNIEXPORT void JNICALL
Java_ph_edu_dlsu_mhealth_vision_OrbSymmetryMatcher_apply__JJJ(JNIEnv *env, jclass type, jlong thiz,
                                                              jlong srcAddr, jlong dstAddr) {

    if (thiz != 0) {
        OrbSymmetryMatcher *self = (OrbSymmetryMatcher *) thiz;
        cv::Mat &src = *(cv::Mat *) srcAddr;
        cv::Mat &dst = *(cv::Mat *) dstAddr;
        self->apply(src, dst);
    }

}







/****************************** DetectionBasedTracker ******************************/




JNIEXPORT jlong JNICALL Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeCreateObject
        (JNIEnv *jenv, jclass, jstring jFileName, jint faceSize) {
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeCreateObject enter");
    const char *jnamestr = jenv->GetStringUTFChars(jFileName, NULL);
    std::string stdFileName(jnamestr);
    jlong result = 0;

    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeCreateObject");

    try {
        cv::Ptr<CascadeDetectorAdapter> mainDetector = cv::makePtr<CascadeDetectorAdapter>(
                cv::makePtr<cv::CascadeClassifier>(stdFileName));
        cv::Ptr<CascadeDetectorAdapter> trackingDetector = cv::makePtr<CascadeDetectorAdapter>(
                cv::makePtr<cv::CascadeClassifier>(stdFileName));
        result = (jlong) new DetectorAgregator(mainDetector, trackingDetector);
        if (faceSize > 0) {
            mainDetector->setMinObjectSize(cv::Size(faceSize, faceSize));
            //trackingDetector->setMinObjectSize(Size(faceSize, faceSize));
        }
    }
    catch (cv::Exception &e) {
        LOGD("nativeCreateObject caught cv::Exception: %s", e.what());
        jclass je = jenv->FindClass("org/opencv/core/CvException");
        if (!je)
            je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, e.what());
    }
    catch (...) {
        LOGD("nativeCreateObject caught unknown exception");
        jclass je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je,
                       "Unknown exception in JNI code of DetectionBasedTracker.nativeCreateObject()");
        return 0;
    }

    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeCreateObject exit");
    return result;
}

JNIEXPORT void JNICALL Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeDestroyObject
        (JNIEnv *jenv, jclass, jlong thiz) {
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeDestroyObject");

    try {
        if (thiz != 0) {
            ((DetectorAgregator *) thiz)->tracker->stop();
            delete (DetectorAgregator *) thiz;
        }
    }
    catch (cv::Exception &e) {
        LOGD("nativeestroyObject caught cv::Exception: %s", e.what());
        jclass je = jenv->FindClass("org/opencv/core/CvException");
        if (!je)
            je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, e.what());
    }
    catch (...) {
        LOGD("nativeDestroyObject caught unknown exception");
        jclass je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je,
                       "Unknown exception in JNI code of DetectionBasedTracker.nativeDestroyObject()");
    }
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeDestroyObject exit");
}

JNIEXPORT void JNICALL Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeStart
        (JNIEnv *jenv, jclass, jlong thiz) {
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeStart");

    try {
        ((DetectorAgregator *) thiz)->tracker->run();
    }
    catch (cv::Exception &e) {
        LOGD("nativeStart caught cv::Exception: %s", e.what());
        jclass je = jenv->FindClass("org/opencv/core/CvException");
        if (!je)
            je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, e.what());
    }
    catch (...) {
        LOGD("nativeStart caught unknown exception");
        jclass je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, "Unknown exception in JNI code of DetectionBasedTracker.nativeStart()");
    }
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeStart exit");
}

JNIEXPORT void JNICALL Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeStop
        (JNIEnv *jenv, jclass, jlong thiz) {
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeStop");

    try {
        ((DetectorAgregator *) thiz)->tracker->stop();
    }
    catch (cv::Exception &e) {
        LOGD("nativeStop caught cv::Exception: %s", e.what());
        jclass je = jenv->FindClass("org/opencv/core/CvException");
        if (!je)
            je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, e.what());
    }
    catch (...) {
        LOGD("nativeStop caught unknown exception");
        jclass je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, "Unknown exception in JNI code of DetectionBasedTracker.nativeStop()");
    }
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeStop exit");
}

JNIEXPORT void JNICALL Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeSetFaceSize
        (JNIEnv *jenv, jclass, jlong thiz, jint faceSize) {
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeSetFaceSize -- BEGIN");

    try {
        if (faceSize > 0) {
            ((DetectorAgregator *) thiz)->mainDetector->setMinObjectSize(
                    cv::Size(faceSize, faceSize));
            //((DetectorAgregator*)thiz)->trackingDetector->setMinObjectSize(Size(faceSize, faceSize));
        }
    }
    catch (cv::Exception &e) {
        LOGD("nativeStop caught cv::Exception: %s", e.what());
        jclass je = jenv->FindClass("org/opencv/core/CvException");
        if (!je)
            je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, e.what());
    }
    catch (...) {
        LOGD("nativeSetFaceSize caught unknown exception");
        jclass je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je,
                       "Unknown exception in JNI code of DetectionBasedTracker.nativeSetFaceSize()");
    }
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeSetFaceSize -- END");
}


JNIEXPORT void JNICALL Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeDetect
        (JNIEnv *jenv, jclass, jlong thiz, jlong imageGray, jlong faces) {
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeDetect");

    try {
        std::vector<cv::Rect> RectFaces;
        ((DetectorAgregator *) thiz)->tracker->process(*((cv::Mat *) imageGray));
        ((DetectorAgregator *) thiz)->tracker->getObjects(RectFaces);
        *((cv::Mat *) faces) = cv::Mat(RectFaces, true);
    }
    catch (cv::Exception &e) {
        LOGD("nativeCreateObject caught cv::Exception: %s", e.what());
        jclass je = jenv->FindClass("org/opencv/core/CvException");
        if (!je)
            je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, e.what());
    }
    catch (...) {
        LOGD("nativeDetect caught unknown exception");
        jclass je = jenv->FindClass("java/lang/Exception");
        jenv->ThrowNew(je, "Unknown exception in JNI code DetectionBasedTracker.nativeDetect()");
    }
    LOGD("Java_ph_edu_dlsu_mhealth_vision_DetectionBasedTracker_nativeDetect END");
}


#ifdef __cplusplus
}
#endif
