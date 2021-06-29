#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pok = "Bulbasaur";
    int arr[300]={0};
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0; i<len; i++)
    {
        arr[s[i]]++;
    }
    int ans = 1000004;
    for(int i=0; i<pok.size(); i++)
    {
        int cnt = arr[pok[i]];
        if(pok[i]=='u' || pok[i]=='a')  cnt=cnt/2;
        ans=min(ans, cnt);
    }
    cout<<ans;

    return 0;
}
