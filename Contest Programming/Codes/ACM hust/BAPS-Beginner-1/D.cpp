#include <bits/stdc++.h>
using namespace std;

long long ar[100005][4], n;
long long dp[100005][4];

long long rec(long long i, long long j)
{
    if(i<0 || j<0 || i==n || j==3)  return 99999999999999;
    if(i==(n-1) && j==1)    return ar[i][j];
    if(dp[i][j]!=-1)    return  dp[i][j];
    long long a=rec(i+1, j-1);
    long long b=rec(i+1, j);
    long long c=rec(i+1, j+1);
    long long d=rec(i, j+1);

    return dp[i][j]=ar[i][j]+min(min(a, b), min(c, d));
}

int main()
{
    long long t=0;
    while(++t)
    {
        cin>>n;
        if(n==0)    break;
        for(long long i=0; i<n; i++)
        {
            for(long long j=0; j<3; j++)
            {
                cin>>ar[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        cout<<t<<". "<<rec(0, 1)<<endl;

    }

    return 0;
}
