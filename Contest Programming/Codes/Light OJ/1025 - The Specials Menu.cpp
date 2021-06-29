#include <bits/stdc++.h>
using namespace std;
string w;
long long dp[65][65];
long long rec(int i, int j)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    if(w[i]==w[j])  return dp[i][j]=1+rec(i, j-1)+rec(i+1, j);
    else return dp[i][j]=rec(i, j-1)+rec(i+1, j)-rec(i+1, j-1);
}
int main()
{
    int cases, t=0;
    cin>>cases;
    while(t++<cases)
    {
        cin>>w;
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %lld\n", t, rec(0, (int)w.size()-1));
    }

    return 0;
}
