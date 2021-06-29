#include<bits/stdc++.h>
using namespace std;

int ara[100];

string encode(int n)
{
    string output;
    for(int i=0;i<n;i++){
        int a=ara[i];
        int sign=0;
        if(a<0) sign=1;
        a=fabs(a);
        string s;
        for(int j=0;j<7;j++){
            if(a%2==0) s+='0';
            else s+='1';
            a/=2;
        }
        s+=(sign+'0');
        reverse(s.begin(),s.end());
        output+=s;
    }
    cout<<"Encoded digital signal is: "<<output<<endl;
    return output;
}

void decode(string s)
{
    cout<<"Decoded amplitudes values are:\n";
    for(int i=0;i<s.size();i+=8){
        int num=0;
        for(int j=i+1;j<i+8;j++){
            num*=2;
            num+=s[j]-'0';
        }
        if(s[i]=='1') num=-num;
        cout<<num<<" ";
    }
    cout<<endl;

}
int main()
{
    int n;
    cout<<"Length of the signal : ";
    cin>>n;
    cout<<"Amplitudes of the signal:\n";
    for(int i=0;i<n;i++){
        cin>>ara[i];
        if(fabs(ara[i])>127){
            cout<<"Error! values have to be between -127 to 127.\nEnter again: ";
            i--;
        }
    }
    string s=encode(n);
    decode(s);
    return 0;
}
