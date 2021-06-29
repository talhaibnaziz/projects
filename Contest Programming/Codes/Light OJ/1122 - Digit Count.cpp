#include <bits/stdc++.h>
using namespace std;
int m, n, dig[12], dp[15][15];
int rec(int pos, int idx)
{
    if(pos==n)  return 1;
    if(idx!=-1 && dp[pos][idx]!=-1) return  dp[pos][idx];
    //cout<<pos<<' '<<idx<<endl;

    int ans=0;
    for(int i=0; i<m; i++)
    {
        if(idx==-1) ans+=rec(pos+1, i);
        else if(abs(dig[i]-dig[idx])<=2) ans+=rec(pos+1, i);
    }
    if(idx!=-1) dp[pos][idx]=ans;
    return ans;
}
int main()
{
    int cases, t=0;
    cin>>cases;
    while(t++<cases)
    {
        cin>>m>>n;
        for(int i=0; i<m; i++)  cin>>dig[i];
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", t, rec(0, -1));
    }

    return 0;
}
