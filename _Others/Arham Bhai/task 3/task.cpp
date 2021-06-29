#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void rev(char s[])
{
    int len=strlen(s);
    for(int i=0, j=len-1; i<len/2; i++, j--)  swap(s[i], s[j]);
}
int check(string name1)
{
    ifstream f1("patient.txt");
    string name2;
    int a,ch=0;
    while(getline(f1,name2))
    {

        if(name1==name2)
        {
            cout<<"Record found\nName: ";

            cout<<name2<<endl;
            getline(f1,name2);
            cout<<"NRIC: "<<name2<<endl;
            getline(f1,name2);
            cout<<"Age: "<<name2;
            getline(f1,name2);
            cout<<"\nAddress: "<<name2;
            getline(f1,name2);
            cout<<"\nDate: "<<name2;
            getline(f1,name2);
            cout<<"\nDiagnosis: "<<name2;
            getline(f1,name2);
            cout<<"\nPrescription: "<<name2;
            getline(f1,name2);
            cout<<"\nFee: "<<name2;
            f1>>a;
            getline(f1,name2);
            if(a==1)
            {
                getline(f1,name2);
                cout<<"\nEmployer: "<<name2;
                getline(f1,name2);
                cout<<"\nMax. sponsored amount: "<<name2;
            }
            cout<<"\n";
            ch=1;
            break;
        }
    }
    f1.close();
    return ch;
}
class patient
{
    public:
        patient(){}
        void add(string s)
        {
            name=s;
            cout<<"NRIC: ";
            cin>>nric;
            cout<<"Age: ";
            cin>>age;
            cout<<"Address: ";
            cin>>address;
            //date ase
            cout<<"Diagnostics: ";
            cin>>diag;
            cout<<"Prescription: ";
            cin>>pres;
            cout<<"Bill: ";
            cin>>bill;
            int choose;
            cout<<"Press 1 if patient is panel-patient , press 2 otherwise: ";
            cin>>choose;

            while(choose!=1 && choose!=2)
            {
                cout<<"Invalid input, re=enter: ";
                cin>>choose;
            }
            if(choose==2)
                panel=false;
            else if(choose==1)
            {
                panel=true;
                cout<<"Employer name: ";
                cin>>emp_name;
                cout<<"Maximum sponsored amount: ";
                cin>>max_amount_spons;
            }
            ofstream fileout("patient.txt", ios::app);
            fileout<<name<<endl<<nric<<endl<<age<<endl<<address<<endl<<__DATE__<<endl<<diag<<endl<<pres<<endl<<bill<<endl;
            if(panel==true) fileout<<"1"<<endl;
            else fileout<<"0"<<endl;
            if(panel==true)
            {
                fileout<<emp_name<<endl<<max_amount_spons<<endl;
            }
            fileout.close();


        }
     //   ~patient();
    protected:
    private:

    string name;
    string nric;
    int age,bill;
    string address;
    string diag;
    string pres;
    string tele;
    bool panel;
    string emp_name;
    int max_amount_spons;
};

class record
{
    public:
        record()
        {

        }
        ~record()
        {

        }
        void add()
        {
            cout<<"Enter name of patient: ";
            getline(cin,patient_name);
            cout<<"Enter fee for consultation: ";
            cin>>fee;
            bool flag=0;
            ifstream fin("records.txt");

            string s;
            while(getline(fin, s))
            {
                if(s==__DATE__)
                {
                    flag=1;
                    break;
                }
            }
            fin.close();

            ofstream fout("records.txt", ios::app);
            if(flag)    fout<<patient_name<<' '<<fee<<endl;
            else    fout<<__DATE__<<endl<<patient_name<<' '<<fee<<endl;
            fout.close();
        }
        void show()
        {
            ifstream fin("records.txt");
            string s;
            int total=0;
            bool flag=0;
            while(getline(fin,s))
            {
                if(s==__DATE__)
                {
                    flag=1;
                    continue;
                }
                if(flag)
                {
                    cout<<s<<endl;
                    char tmp[20];
                    int j, i;
                    for(i=s.size()-1, j=0; i>=0; i--, j++)
                    {
                        if(s[i]==' ')   break;
                        tmp[j]=s[i];
                    }
                    tmp[j]='\0';
                    rev(tmp);
                    total+=atoi(tmp);
                }
            }
            cout<<"Total Fee: "<<total<<endl;
        }
    protected:
    private:
        int day, month, year;
        string patient_name;
        int fee;
};


int main()
{
    while(1)
    {
        cout<<"1. Patient data\n2. Consultation record\n3. Exit System\nEnter Choice: ";
        int choice;
        cin>>choice;
        getchar();
        if(choice==1)
        {
            ifstream fin1("patient.txt");
            string name1;
            int a,b;
            cout<<"Enter patient name:";
            getline(cin,name1);
            b=check(name1);
            if(b==0)
            {

                cout<<"No prevoius record"<<endl;
                patient p1;
                p1.add(name1);
            }
            fin1.close();
        }
        else if(choice==2)
        {
            record r;
            cout<<"1. Add Record\n2. See Record\nEnter choice: ";
            int c;
            cin>>c;
            getchar();
            if(c==1)    r.add();
            else r.show();
        }
        else if(choice==3)
        {
            cout<<"Exiting System..."<<endl;
            break;
        }
        else
        {
            cout<<"Wrong input!!"<<endl;
        }
    }

    return 0;
}
