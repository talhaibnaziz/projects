#include<bits/stdc++.h>
using namespace std;

void data_to_code()
{
    string s1,s2;
    cout<<"Enter divisor: ";
    cin>>s1;
    cout<<"Enter dataword: ";
    cin>>s2;
    cout<<"Augmented bits value: ";
    int ag;
    cin>>ag;
    int a=0,b=0;
    for(int i=0;i<s1.size();i++){
        int t=s1[i]-'0';
        a*=2;
        a+=t;
    }
    for(int i=0;i<s2.size();i++){
        int t=s2[i]-'0';
        b*=2;
        b+=t;
    }
    b=b<<ag;
    int c=b%a;
    string s;
    for(int i=0;i<ag;i++){
        int t=c%2;
        s+='0'+t;
        c/=2;
    }
    reverse(s.begin(),s.end());
    cout<<"The Code word: "<<s2+s<<endl;
}

void code_to_data()
{
    string s1,s2;
    cout<<"Enter divisor: ";
    cin>>s1;
    cout<<"Enter codeword: ";
    cin>>s2;
    cout<<"Augmented bits value: ";
    int ag;
    cin>>ag;
    int a=0,b=0;
    cout<<s1<<" "<<s2<<endl;
    for(int i=0;i<s1.size();i++){
        int t=s1[i]-'0';
        a*=2;
        a+=t;
    }
    for(int i=0;i<s2.size()-ag;i++){
        int t=s2[i]-'0';
        b*=2;
        b+=t;
    }
    b=b<<ag;
    int c=b%a;
    int rem=0;
    for(int i=s2.size()-ag;i<s2.size();i++){
        int t=s2[i]-'0';
        rem*=2;
        rem+=t;
    }
    if(c!=rem){
        cout<<"Codeword is invalid\n";
        return;
    }
    cout<<"The data word is: ";
    for(int i=0;i<s2.size()-ag;i++) cout<<s2[i];
    cout<<endl;
}
int main()
{
    data_to_code();
    code_to_data();

}
