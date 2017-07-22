package ph.edu.dlsu.mhealth.vision.interfaces;

import org.opencv.core.Mat;

/**
 * Created by cobalt on 1/7/16.
 */
public interface NativeMatcher {

    public abstract void apply(final Mat src, final Mat dst, String descriptorType);

    public abstract void release();

}
