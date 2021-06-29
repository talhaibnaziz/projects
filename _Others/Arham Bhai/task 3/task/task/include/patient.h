#ifndef PATIENT_H
#define PATIENT_H
#include<bits/stdc++.h>
using namespace std;



class patient
{
    public:
        patient();
        virtual ~patient();
    protected:
    private:

    string name;
    string nric;
    int age;
    string address;
    string tele;
    bool panel;
    string emp_name;
    int max_amount_spons;



};

#endif // PATIENT_H
