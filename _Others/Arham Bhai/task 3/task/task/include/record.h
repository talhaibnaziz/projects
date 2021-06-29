#ifndef RECORD_H
#define RECORD_H

#include<bits/stdc++.h>
using namespace std;
class record
{
    public:
        record();
        virtual ~record();
    protected:
    private:
        string date;
        string patient_name;
        string fee;
        string diagnosis;
        string prescription;


};

#endif // RECORD_H

