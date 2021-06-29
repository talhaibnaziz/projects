#include <bits/stdc++.h>
using namespace std;
int n, ar[110];
double dp[110];
bool vis[110];
double rec(int pos)
{
    //cout<<pos<<endl;
    if(vis[pos]) return dp[pos];
    double ans=0, den=6;
    for(int i=1; i<=6; i++)
    {
        if((pos+i)<n)   ans+=rec(pos+i);
        else    den--;
    }
    vis[pos]=1;
    if(den==0)  return dp[pos]=ar[pos];
    return  dp[pos]=ans/den+(double)ar[pos];
}
int main()
{
    //freopen("out.txt", "w", stdout);
    int cases, t=0;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>ar[i];
        memset(vis, 0, sizeof(vis));
        printf("Case %d: %lf\n", t, rec(0));
    }

    return 0;
}
