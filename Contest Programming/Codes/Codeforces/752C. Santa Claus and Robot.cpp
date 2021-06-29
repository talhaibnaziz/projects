#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool l=0, r=0, u=0, d=0;
    string s;
    cin>>s;
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if((s[i]=='R' && l) || (s[i]=='L' && r) || (s[i]=='U' && d) || (s[i]=='D' && u))
        {
            cnt++;
            l=0; r=0; u=0; d=0;
            //cout<<i<<endl;
        }
        if(s[i]=='R')   r=1;
        if(s[i]=='L')   l=1;
        if(s[i]=='U')   u=1;
        if(s[i]=='D')   d=1;
    }
    cnt++;
    printf("%d", cnt);

    return 0;
}
