package ph.edu.dlsu.mhealth.vision;

import org.opencv.core.Mat;

import ph.edu.dlsu.mhealth.vision.interfaces.NativeObject;

/**
 * Created by cobalt on 6/25/16.
 */

public final class CMT implements NativeObject {

    static {
        // Load the native library if it is not already loaded.
        System.loadLibrary("mhealth_vision");
    }

    public CMT() {
        mNativeAddr = nativeCreateObject();
    }


    public boolean initialize(final Mat srcGray, long xTopLeft, long yTopLeft, long width, long height) {
        return initialize(mNativeAddr, srcGray.getNativeObjAddr(), xTopLeft, yTopLeft, width, height);
    }

    public void release() {
        nativeDestroyObject(mNativeAddr);
        mNativeAddr = 0;
    }



    public void apply(final Mat src, final Mat dst) {
        apply(mNativeAddr, src.getNativeObjAddr(),
                dst.getNativeObjAddr());
    }


    // Ensure that release() is always called at least once
    // before the object is garbage-collected. This is calling
    // automatic memory management as a fallback if there is no
    // manual call to dispose.
    @Override
    protected void finalize() throws Throwable {
        release();
        super.finalize();
    }



    private long mNativeAddr = 0;

    private static native long nativeCreateObject();

    private static native void nativeDestroyObject(long thiz);

    private static native boolean initialize(long thiz, long srcAddr, long xTopLeft, long yTopLeft, long width, long height);

    private static native void apply(long thiz, long srcAddr, long dstAddr);

}