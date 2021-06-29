#include <iostream>
#include <fstream>
#include "player.h"
#include "questionmc.h"
#include "questionsa.h"
#include "questiontf.h"

using namespace std;

int main()
{
    player p;
    ifstream fin;
    string str;
    cout<<"What is your first name?"<<endl;
    cin>>str;
    p.setfirstname(str);
    cout<<"What is your last name?"<<endl;
    cin>>str;
    p.setlastname(str);
    while(1)
    {
        cout<<"Which file stores your questions?"<<endl;
        cin>>str;
        fin.open(str);
        if(fin) break;
        cout<<"There is no such file!"<<endl;
    }
    int qnum, cnt;
    fin>>qnum;
    while(1)
    {
        cout<<"How many questions would you like (out of "<<qnum<<")?"<<endl;
        cin>>cnt;
        if(cnt<=qnum)   break;
        cout<<"Sorry, that is too many."<<endl;
    }
    for(int i=0; i<cnt; i++)
    {
        string type;
        fin>>type;
        if(type=="TF")
        {
            questiontf qtf;
            int point;
            fin>>point;
            qtf.setpoint(point);
            string statement;
            getline(fin, statement);
            getline(fin, statement);
            qtf.setstatement(statement);
            string answer;
            fin>>answer;
            if(answer=="true")  qtf.setanswer(1);
            else    qtf.setanswer(0);

            cout<<qtf.getstatement()<<endl;
            cin>>answer;
            if((answer=="true" && qtf.getanswer()==1) || (answer=="false" && qtf.getanswer()==0))
            {
                cout<<"Correct Answer!"<<endl;
                p.addpoint(qtf.getpoint());
            }
            else
            {
                cout<<"Incorrect Answer!"<<endl;
                p.addpoint(-1*qtf.getpoint());
            }
        }
        else if(type=="MC")
        {
            questionmc qmc;
            int point;
            fin>>point;
            qmc.setpoint(point);
            string statement;
            getline(fin, statement);
            getline(fin, statement);
            qmc.setstatement(statement);
            int choicecnt;
            fin>>choicecnt;
            string choices[8];
            getline(fin, choices[0]);
            for(int i=0; i<choicecnt; i++)    getline(fin,choices[i]);
            qmc.setchoices(choices, choicecnt);
            char ch;
            fin>>ch;
            qmc.setanswer(ch);

            cout<<qmc.getstatement()<<endl;
            for(int i=0; i<qmc.getchoicecnt(); i++)    cout<<(char)('A'+i)<<") "<<qmc.getchoice(i)<<endl;
            cin>>ch;
            if(ch==qmc.getanswer())
            {
                cout<<"Correct Answer!"<<endl;
                p.addpoint(qmc.getpoint());
            }
            else
            {
                cout<<"Incorrect Answer!"<<endl;
                p.addpoint(-1*qmc.getpoint());
            }
        }
        else
        {
            questionsa qsa;
            int point;
            fin>>point;
            qsa.setpoint(point);
            string statement;
            getline(fin, statement);
            getline(fin, statement);
            qsa.setstatement(statement);
            string answer;
            fin>>answer;
            qsa.setanswer(answer);

            cout<<qsa.getstatement()<<endl;
            cin>>answer;
            if(answer == qsa.getanswer())
            {
                cout<<"Correct Answer!"<<endl;
                p.addpoint(qsa.getpoint());
            }
            else
            {
                cout<<"Incorrect Answer!"<<endl;
                p.addpoint(-1*qsa.getpoint());
            }
        }
    }
    cout<<"Your Name: "<<p.getfirstname()<<' '<<p.getlastname()<<endl;
    cout<<"Your Points: "<<p.getpoint()<<endl;
    fin.close();

    return 0;
}
