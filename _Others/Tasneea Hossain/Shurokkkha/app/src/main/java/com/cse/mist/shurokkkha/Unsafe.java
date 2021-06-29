package com.cse.mist.shurokkkha;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.google.firebase.auth.FirebaseAuth;

public class Unsafe extends AppCompatActivity implements View.OnClickListener {
    private Button logoutBtn;
    private Button followBtn;
    private Button assaultBtn;
    private Button violenceBtn;
    private FirebaseAuth firebaseAuth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_unsafe);
        firebaseAuth = FirebaseAuth.getInstance();

        logoutBtn = (Button) findViewById(R.id.buttonLogout);

        logoutBtn.setOnClickListener(this);
    }
       /* firebaseAuth = FirebaseAuth.getInstance();


        logoutBtn = (Button) findViewById(R.id.buttonLogout);
        followBtn = (Button) findViewById(R.id.FollowedButton);
        assaultBtn = (Button) findViewById(R.id.AssaultButton);
        violenceBtn = (Button) findViewById(R.id.ViolenceButton);
        logoutBtn.setOnClickListener(this);*/
    //}


    @Override
    public void onClick(View view) {
        if (view == logoutBtn) {
            firebaseAuth.signOut();
            startActivity(new Intent(Unsafe.this, SignInActivity.class));
        }
    }
      /*  else if (view==followBtn)
        {
            startActivity(new Intent(Unsafe.this,FeelingUnsafe.class));
        }
        else if(view==assaultBtn){
            startActivity(new Intent(Unsafe.this,FeelingUnsafe.class));
        }
        else if(view==violenceBtn){
            startActivity(new Intent(Unsafe.this,DomesticViolence.class));
        }*/



    public void clickAssault(View view) {
        Intent i = new Intent(this, FeelingUnsafe.class);
        startActivity(i);

    }

    public void clickViolence(View view) {
      //  Intent i = new Intent(this, DomesticViolence.class);
        Intent i = new Intent(this,DomesticViolence.class);
        startActivity(i);

    }

    public void clickFollowed(View view) {
        Intent i = new Intent(this, FeelingUnsafe.class);
        startActivity(i);

    }
}

