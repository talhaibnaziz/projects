#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int len = s.size(), cnt1=0, cnt2=0;
    for(int i=0; i<len; i++)
    {
        if(s[i]=='A')   cnt1++;
        else cnt2++;
    }
    if(cnt1>cnt2)   printf("Anton");
    else if(cnt2>cnt1)  printf("Danik");
    else printf("Friendship");

    return 0;
}
