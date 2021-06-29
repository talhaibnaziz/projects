package com.cse.mist.shurokkkha;

import android.app.ProgressDialog;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class SignInActivity extends AppCompatActivity implements View.OnClickListener {

    //define all the views
    private Button buttonSignin;
    private EditText editTextEmail;
    private EditText editTextPassword;
    private TextView textViewSignup;

    private ProgressDialog progressDialog;

    // defining FirebaseAuth
    private FirebaseAuth firebaseAuth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_in);

        firebaseAuth = FirebaseAuth.getInstance();

        //if someone is already logged in
        if (firebaseAuth.getCurrentUser() != null){
            finish(); // then close this activity
            startActivity(new Intent(SignInActivity.this, ProfileActivity.class)); // and go to their profile page
        }

        //initializing all the views
        editTextEmail = (EditText) findViewById(R.id.editTextEmailLogin);
        editTextPassword = (EditText) findViewById(R.id.editTextPasswordLogin);

        buttonSignin = (Button) findViewById(R.id.buttonSignin);
        textViewSignup = (TextView) findViewById(R.id.linkSignUp);

        progressDialog = new ProgressDialog(this);

        buttonSignin.setOnClickListener(this);

        textViewSignup.setOnClickListener(this);

    }

    @Override
    public void onClick(View view) {
        if (view == buttonSignin){
            userLogin();
        }
        if (view == textViewSignup){
            startActivity(new Intent(SignInActivity.this, SignUpActivity.class));
        }
    }

    private void userLogin() {

        //getting all the inputs from the user
        String email = editTextEmail.getText().toString().trim();
        String password = editTextPassword.getText().toString().trim();

        //validation
        if (TextUtils.isEmpty(email)){
            Toast.makeText(this, "Please enter email!", Toast.LENGTH_SHORT).show();
            return;
        }

        if (TextUtils.isEmpty(password)){
            Toast.makeText(this, "Please enter password!", Toast.LENGTH_SHORT).show();
            return;
        }

        if (password.length() <= 5){
            Toast.makeText(this, "Password must be more than 5 characters!", Toast.LENGTH_SHORT).show();
            return;
        }

        progressDialog.setMessage("Signing in, Please Wait...");
        progressDialog.show();

        firebaseAuth.signInWithEmailAndPassword(email, password)
                .addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
                    @Override
                    public void onComplete(@NonNull Task<AuthResult> task) {
                        if (task.isSuccessful()){
                            finish();
                            progressDialog.hide();
                            startActivity(new Intent(getApplicationContext(), ProfileActivity.class));
                        } else {
                            Toast.makeText(SignInActivity.this, "Invalid Credentials!", Toast.LENGTH_SHORT).show();
                            progressDialog.hide();
                        }
                    }
                });

    }
}
