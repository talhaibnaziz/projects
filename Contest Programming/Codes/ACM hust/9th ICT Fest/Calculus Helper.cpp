#include <bits/stdc++.h>
using namespace std;

int p[12];
int coef[12];
int cnt, numcnt, s;
vector <int> numbers;
string str;

void process(int start)
{
    if(start==s)  return;
    int idx = start;
    int val;
    if(str[idx]>='2' && str[idx]<='9')
    {
        val = str[idx]-'0';
        idx++;
    }
    else if(str[idx]=='1')
    {
        if((idx+1)!=s && str[idx+1]=='0')
        {
            val = 10;
            idx+=2;
        }
        else
        {
            val = 1;
            idx++;
        }
    }
    else
    {
        idx++;
        process(idx);
        return;
    }
    numbers.push_back(val);
    //cout<<idx<<' '<<val<<endl;
    process(idx);
}
void process2(int idx)
{
    if(idx==s)  return;
    if(str[idx]=='X')
    {
        if(idx!=0 && str[idx-1]=='*')
        {
            coef[cnt]=numbers[numcnt];
            numcnt++;
        }
        else    coef[cnt]=1;
        process2(idx+1);
    }
    else if(str[idx]=='^')
}
int main()
{
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int o;
        cin>>o;
        getchar();
        getline(cin, str);
        cnt=0;
        s = str.size();
        numbers.clear();
        process(0);
        process2(0);

    }
}
