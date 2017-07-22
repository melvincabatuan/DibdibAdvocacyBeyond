package ph.edu.dlsu.mhealth.android;

import android.content.Context;
import android.graphics.Color;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.cabatuan.breastfriend.R;

/**
 * Created by cobalt on 1/4/16.
 */
public class MyUtils {

    public static void showToast(Context context, String message, int imageId) {

        LayoutInflater inflater = LayoutInflater.from(context);

        View layout = inflater.inflate(R.layout.mytoast, null);

        // Retrieve the ImageView and TextView
        ImageView iv = (ImageView) layout.findViewById(R.id.toastImageView);
        TextView text = (TextView) layout.findViewById(R.id.textToShow);

        // Set the ImageView's image
        iv.setImageResource(imageId);

        // Set the Text to show in TextView
        text.setText(message);
        text.setBackgroundColor(Color.BLACK);

        final Toast toast = new Toast(context);
        toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
        toast.setDuration(Toast.LENGTH_SHORT);
        toast.setView(layout);
        toast.show();
    }

}
