package com.cse.mist.shurokkkha;


import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.google.firebase.auth.FirebaseAuth;

public class ProfileActivity extends AppCompatActivity implements View.OnClickListener {

    private Button logoutBtn;
    private FirebaseAuth firebaseAuth;
public void onClickReached(View view){

        ///map dibo
        Intent i = new Intent(this, TrustedContacts.class);
        startActivity(i);



}
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_profile);

        firebaseAuth = FirebaseAuth.getInstance();

        logoutBtn = (Button) findViewById(R.id.buttonLogout);

        logoutBtn.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        if (view == logoutBtn){
            firebaseAuth.signOut();
            startActivity(new Intent(ProfileActivity.this, SignInActivity.class));
        }
    }

    public void onClickUnsafe(View view) {
        ///map dibo
        Intent i = new Intent(this, Unsafe.class);
        startActivity(i);

    }
}
