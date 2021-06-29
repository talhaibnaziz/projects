#include <bits/stdc++.h>
using namespace std;

int ar[]={0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int rod;
int dp[10][100][100];
int rodcut(int cuts, int len, int price)
{
    if(len>rod) return 0;
    cout<<len<<' ';
    if(len==rod)
    {
        printf("%d %d\n", price, cuts);
        return price-((cuts-1)*2);
    }
    if(dp[cuts][len][price]!=-1)  return dp[cuts][len][price];
    int ans=0;
    for(int i=1; i<=(len+i) && i<=4; i++)
    {
        ans=max(ans, rodcut(cuts+1, len+i, price+ar[i]));
    }
    return dp[cuts][len][price]=ans;
}
int main()
{
    rod=4;
    memset(dp, -1, sizeof(dp));
    cout<<rodcut(0, 0, 0);

    return 0;
}
