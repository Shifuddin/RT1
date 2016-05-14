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
    String fileName = "/info.txt";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_formal_);

        final Button runApp = (Button) findViewById(R.id.button_run);
        final Button fetch_ident = (Button)findViewById(R.id.button_fetch);
        final Button false_ident = (Button)findViewById(R.id.button_false);

        /*
         * Purpose: Match identification data
         * Steps: 1. Create new thread
         *        2. Call match_ident method from the native library
         *        3. If match founds, runs our homework app
         *        4. If not, notify user
        */
        runApp.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view)
            {

                Formal_Activity.this.runOnUiThread(new Runnable() {
                    public void run() {
                        NativeLibrary nativeLibrary = new NativeLibrary();
                        isMatch = nativeLibrary.match_ident(getApplicationContext().getFilesDir().getAbsolutePath()+fileName);
                        if(isMatch == 0)
                        {
                            Intent intent = new Intent(Formal_Activity.this, MainActivity.class);
                            Formal_Activity.this.startActivity(intent);
                        }
                        else
                        {
                            showNotification("Unrecognized Device !");
                        }
                    }
                });

            }

            });
        /*
         * Purpose: Fetch identification data
         * Steps: 1. Create new thread
         *        2. Call fetch_ident method from the native library
        */
        fetch_ident.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view)
            {

                
                new Thread(new Runnable() {
                    public void run() {
                        NativeLibrary nativeLibrary = new NativeLibrary();
                        nativeLibrary.fetch_ident( getApplicationContext().getFilesDir().getAbsolutePath()+fileName);

                    }
                }).start();
                showNotification("Fetching Information .........");
            }


        });

        /*
         * Purpose: Write false identification data
         * Steps: 1. Create new thread
         *        2. Call false_ident method from the native library
        */
        false_ident.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view)
            {

                new Thread(new Runnable() {
                    public void run() {
                        NativeLibrary nativeLibrary = new NativeLibrary();
                        nativeLibrary.false_ident(getApplicationContext().getFilesDir().getAbsolutePath()+fileName);

                    }
                }).start();
                showNotification("Inserting False Info...!");
            }


        });

    }
    /*
     * Purpose: Show custom notification to user
    */
    public void showNotification(String message)
    {
        Context context = getApplicationContext();
        int duration = Toast.LENGTH_LONG;

        Toast toast = Toast.makeText(context, message, duration);
        toast.show();
    }
}
