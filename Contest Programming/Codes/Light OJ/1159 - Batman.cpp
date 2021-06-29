#include <bits/stdc++.h>
using namespace std;
string stra, strb, strc;
int strla, strlb, strlc;
int dp[55][55][55];
int rec(int i, int j, int k)
{
    if(i==strla || j==strlb || k==strlc)    return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(stra[i]==strb[j] && strb[j]==strc[k])    return dp[i][j][k]=1+rec(i+1, j+1, k+1);
    return dp[i][j][k]=max(rec(i+1, j, k), max(rec(i, j+1, k), rec(i, j, k+1)));
}
int main()
{
    int cases, t=0;
    cin>>cases;
    while(t++<cases)
    {
        cin>>stra;
        cin>>strb;
        cin>>strc;
        strla=stra.size();
        strlb=strb.size();
        strlc=strc.size();
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", t, rec(0, 0, 0));
    }
    return 0;
}
