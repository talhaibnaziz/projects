#include <bits/stdc++.h>
using namespace std;

long long n;
int dp[1000000];
bool rec(long long p)
{
    //cout<<p<<endl;
    if(p<1000000 && dp[p]!=-1)  return dp[p];
    if(p>=n)
    {
        if(p<1000000)   dp[p]=1;
        return 1;
    }
    for(long long i=2; i<10; i++)
    {
        if(rec(i*p))
        {
            if(p<1000000)   dp[p]=0;
            return 0;
        }
    }
    if(p<1000000)   dp[p]=1;
    return 1;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%lld", &n)==1)
    {
        memset(dp, -1, sizeof dp);
        if(rec(1))  printf("Ollie wins.\n");
        else    printf("Stan wins.\n");
    }

    return 0;
}
