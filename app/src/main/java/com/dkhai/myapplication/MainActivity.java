package com.dkhai.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native int add(int x, int y);

    public native String sayHelloInc(String s);

    public native int[] intMethod(int[] nums);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClick(View view) {
        int id = view.getId();
        switch (id) {
            case R.id.add:
                int result = add(1, 2);
                Toast.makeText(getApplicationContext(), "the add result : " + result, Toast.LENGTH_LONG).show();
                break;

            case R.id.sayHelloInc:
                Toast.makeText(getApplicationContext(), sayHelloInc("Hello"), Toast.LENGTH_LONG).show();
                break;

            case R.id.intMethod:
                int[] array = {1, 2, 3, 4, 5};
                intMethod(array);
                break;

            default:
                break;
        }
    }
}