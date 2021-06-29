package com.cse.mist.shurokkkha;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.google.firebase.auth.FirebaseAuth;

public class DomesticViolence extends AppCompatActivity implements View.OnClickListener{
    private Button logoutBtn;
    private FirebaseAuth firebaseAuth;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_domestic_violence);


        firebaseAuth = FirebaseAuth.getInstance();

        logoutBtn = (Button) findViewById(R.id.LogOut3Button);

        logoutBtn.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        if (view == logoutBtn){
            firebaseAuth.signOut();
            startActivity(new Intent(DomesticViolence.this, SignInActivity.class));
        }
    }
}
