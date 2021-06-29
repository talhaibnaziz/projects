#include <bits/stdc++.h>
using namespace std;
string str;
int dp[110][110];

int rec(int i, int j)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    if(str[i]==str[j])  return dp[i][j]=rec(i+1, j-1);
    else
    {
        return dp[i][j]=min(rec(i+1, j), rec(i, j-1))+1;
    }
}
int main()
{
    int t=0, cases;
    cin>>cases;
    while(t<cases)
    {
        cin>>str;
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", ++t, rec(0, (int)str.size()-1));
    }
    return 0;
}
