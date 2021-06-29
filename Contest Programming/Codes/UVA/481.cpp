#include <bits/stdc++.h>
using namespace std;

int ar[5005], n, ans, cnt;
int dp[2][5005][5005];

int rec(bool sig, int i, int prev)
{
    if(i==n)    return 0;
    if(dp[sig][i][prev]!=-1)    return dp[sig][i][prev];
    cnt++;
    //cout<<sig<<' '<<i<<' '<<prev<<endl;
    bool sig2;
    if(ar[i]<0) sig2=1;
    else    sig2=0;
    if(sig) prev*=-1;
    if(ar[i]>prev)  return dp[sig][i][prev]=max(rec(sig, i+1, abs(prev)), rec(sig2, i+1, abs(ar[i]))+1);
    else    return  dp[sig][i][prev]=rec(sig, i+1, abs(prev));
}
vector <int> v, v2;
void rec2(int i, int nxt)
{
    if(v2.size()==ans)   return;
    //cout<<v.size()<<endl;
    if(v.size()==ans)
    {
        v2=v;
        //cout<<v.size()<<' '<<v2.size()<<endl;
        return;
    }
    if(i==-1)   return;
    //cout<<i<<' '<<nxt<<endl;
    if(ar[i]<nxt)
    {
        v.push_back(ar[i]);
        rec2(i-1, ar[i]);
        v.pop_back();
    }
    rec2(i-1, nxt);
}
int main()
{
    //freopen("out.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
    n=0;
    int in;
    while(scanf("%d", &ar[n])==1)
    {
        n++;
    }
    //cout<<"HERE"<<endl;
    memset(dp, -1, sizeof dp);
    ans=rec(1, 0, 5004);
    printf("%d\n-\n", ans);
    //rec2(n-1, 99999999);

    for(int i=v2.size()-1; i>=0; i--)  printf("%d\n", v2[i]);
    return 0;
}
