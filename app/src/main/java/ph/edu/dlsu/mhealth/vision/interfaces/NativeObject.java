package ph.edu.dlsu.mhealth.vision.interfaces;


import org.opencv.core.Mat;

public interface NativeObject {

    public abstract void apply(final Mat src, final Mat dst);

    public abstract void release();

}
