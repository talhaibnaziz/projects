package com.cse.mist.shurokkkha;

import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private static int Splash_time=2000;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        new Handler().postDelayed(new Runnable(){
            @Override
            public void run(){
                Intent homeIntent= new Intent(MainActivity.this,Start.class);
                startActivity(homeIntent);
                finish();
            }
        },Splash_time);
    }
    /*public void onClick(View view){
        Intent i= new Intent(this,Start.class);
        startActivity(i);
    }*/
}
