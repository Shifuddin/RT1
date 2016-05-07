package masud.shifuddin.directionpointer;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class Formal_Activity extends AppCompatActivity {

    int isMatch;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_formal_);

        final Button runApp = (Button) findViewById(R.id.button_run);
        final Button fetch_ident = (Button)findViewById(R.id.button_fetch);
        final Button false_ident = (Button)findViewById(R.id.button_false);

        runApp.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view)
            {

                new Thread(new Runnable() {
                    public void run() {
                        NativeLibrary nativeLibrary = new NativeLibrary();
                        isMatch = nativeLibrary.match_ident();
                        if(isMatch == 0)
                        {
                            Intent intent = new Intent(Formal_Activity.this, MainActivity.class);
                            Formal_Activity.this.startActivity(intent);
                        }
                        else
                        {
                           // showNotification("Unrecognized Device!");
                        }
                    }
                }).start();




            }


            });

        fetch_ident.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view)
            {

                new Thread(new Runnable() {
                    public void run() {
                        NativeLibrary nativeLibrary = new NativeLibrary();
                        nativeLibrary.fetch_ident();

                    }
                }).start();
                showNotification("Fetching Information .........");
            }


        });

        false_ident.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view)
            {

                new Thread(new Runnable() {
                    public void run() {
                        NativeLibrary nativeLibrary = new NativeLibrary();
                        nativeLibrary.false_ident();

                    }
                }).start();
                showNotification("Inserting False Info...!");
            }


        });

    }
    public void showNotification(String message)
    {
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_LONG;

        Toast toast = Toast.makeText(context, message, duration);
        toast.show();
    }
}
