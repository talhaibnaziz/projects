#include <bits/stdc++.h>
using namespace std;
int dp[10][30010];
int ar[]={1, 5, 10, 25, 50};
int n;

int rec(int i, int sum)
{
    if(i==5)    return 0;
    if(sum>n)   return 0;
    if(sum==n)  return 1;
    if(dp[i][sum]!=-1)  return dp[i][sum];
    return dp[i][sum]=rec(i+1, sum)+rec(i, sum+ar[i]);
}
int main()
{
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<rec(0, 0);

    return 0;
}
