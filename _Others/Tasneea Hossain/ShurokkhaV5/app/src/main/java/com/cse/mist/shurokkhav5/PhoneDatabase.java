package com.cse.mist.shurokkhav5;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.List;

public class PhoneDatabase extends AppCompatActivity {

    EditText name, number;
    Button buttonAdd;

    DatabaseReference databaseContacts;
    ListView listViewContacts;
    List<Contacts>contactList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_phone_database);

        databaseContacts = FirebaseDatabase.getInstance().getReference("contacts");

        name = (EditText) findViewById(R.id.nameText);
        number = (EditText) findViewById(R.id.numberText);
        buttonAdd = (Button) findViewById(R.id.addButton);
        listViewContacts=(ListView)findViewById(R.id.listViewContacts);
        contactList=new ArrayList<>();
        buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                addTrustedContacts();
            }
        });
        Bundle bundle = getIntent().getExtras();
        if(bundle!=null){


        }

        listViewContacts.setOnItemClickListener(new AdapterView.OnItemClickListener() {

            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

             /*   //ContactsList adapter = new ContactsList(PhoneDatabase.this,contactList);
                PhoneDatabase phoneDatabase= (PhoneDatabase) adapter.getNumber(); // ekhane .getNumber()
                Intent i = new Intent(this, MainActivity.class);
                // i.putExtra("Editing", imageUpload);
                startActivity(i);*/
            }
        });

    }

    @Override
    public void onBackPressed() {
        startActivity(new Intent(this,NavigationActivity.class));
    }

    @Override
    protected void onStart() {
        super.onStart();


        databaseContacts.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                contactList.clear();
                for(DataSnapshot contactsSnapshot : dataSnapshot.getChildren()){
                 Contacts contacts = contactsSnapshot.getValue(Contacts.class);
                    contactList.add(contacts);
                }

                ContactsList adapter = new ContactsList(PhoneDatabase.this,contactList);
                listViewContacts.setAdapter(adapter);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });
    }

    private void addTrustedContacts() {
        String contactName = name.getText().toString().trim();
        String phone = number.getText().toString().trim();
        if (phone.length() < 11) {
            Toast.makeText(this, "Must contain 11 digits!", Toast.LENGTH_SHORT).show();
        }else{
        if (!TextUtils.isEmpty(contactName) && !TextUtils.isEmpty(phone)) {

            String id = databaseContacts.push().getKey();

            Contacts contacts = new Contacts(id, contactName, phone);
            databaseContacts.child(id).setValue(contacts);
            Toast.makeText(this, "Contact Added!", Toast.LENGTH_SHORT).show();
            startActivity(new Intent(this, PhoneDatabase.class));
        }/* else if (!TextUtils.isEmpty(phone)) {

        }*/ else {
            Toast.makeText(this, "Enter all Fields!", Toast.LENGTH_SHORT).show();
        }
    }
    }
}