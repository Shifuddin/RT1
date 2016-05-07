package masud.shifuddin.directionpointer;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.Button;
import android.widget.ImageView;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Define image views
        final ImageView leftImageView = (ImageView) findViewById(R.id.imageViewLeft);
        final ImageView rightImageView = (ImageView) findViewById(R.id.imageViewRight);
        final ImageView downImageView = (ImageView) findViewById(R.id.imageViewDown);

        //Define button
        final Button clickMe = (Button) findViewById(R.id.button);

        //Create an AlphaAnimation
        final Animation fadeOut = new AlphaAnimation(1, 0);

        //set properties of the animation
        fadeOut.setStartOffset(1000);
        fadeOut.setDuration(1000);

        //set animation to Image Views
        leftImageView.setAnimation(fadeOut);
        rightImageView.setAnimation(fadeOut);
        downImageView.setAnimation(fadeOut);

        //listener for fadeOut animation
        fadeOut.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation)
            {

            }
            @Override
            public void onAnimationEnd(Animation animation)
            {
                //After the end of animation make all views invisible & visible the button to tap
                leftImageView.setVisibility(View.GONE);
                rightImageView.setVisibility(View.GONE);
                downImageView.setVisibility(View.GONE);
                clickMe.setVisibility(View.VISIBLE);
            }
            @Override
            public void onAnimationRepeat(Animation animation)
            {

            }
        });

        //onClick listener of clickMe button
        clickMe.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view)
            {
                //create an instance of Random
                Random random = new Random();
                //Generate a number from 0 to 2
                int number = random.nextInt(3);

                //first invisible the button
                clickMe.setVisibility(View.GONE);

                // check random number and show corresponding image view
                switch (number)
                {
                    case 0:
                        leftImageView.setVisibility(View.VISIBLE);
                        leftImageView.startAnimation(fadeOut);
                        break;

                    case 1:
                        rightImageView.setVisibility(View.VISIBLE);
                        rightImageView.startAnimation(fadeOut);
                        break;

                    case 2:
                        downImageView.setVisibility(View.VISIBLE);
                        downImageView.startAnimation(fadeOut);
                        break;

                    default:
                        break;
                }
            }
        });
    }
}
