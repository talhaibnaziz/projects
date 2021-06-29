package com.cse.mist.shurokkhav5;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class SendSmsSafe extends AppCompatActivity {
    EditText no,msg;
    String num,sms;
    Button btnSendSms;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_send_sms_safe);
        no=(EditText)findViewById(R.id.numText);
        msg=(EditText)findViewById(R.id.msgText);
        num=no.getText().toString();
        btnSendSms=(Button)findViewById(R.id.button3);}
    public void sendSMS(View v){


        num=no.getText().toString();
        sms=msg.getText().toString();
        if(!sms.isEmpty()){
            startActivity(new Intent(Intent.ACTION_VIEW,Uri.fromParts("sms",num,"llala")).putExtra("sms_body",sms));}
        else  startActivity(new Intent(Intent.ACTION_VIEW,Uri.fromParts("sms",num,"llala")).putExtra("sms_body","Reached Safely!"));


    }

      /*  btnSendSms.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
           /*     String uri="smsto"+num;
                Intent intent= new Intent(Intent.ACTION_SENDTO);
                intent.setData(Uri.parse(uri));
                startActivity(intent);*/
    //  Intent smsIntent = new Intent(Intent.ACTION_SENDTO, Uri.parse("smsto:01716472113"));
    //     smsIntent.putExtra("sms_body","Reached Safely");
    //  startActivity(smsIntent);
    /*        }
        });

        */
}
    /*
    protected void sendSms(){
String number=no.getText().toString();
String message=msg.getText().toString();
        SmsManager manager = new SmsManager.getDefault();

    }*/
//}

