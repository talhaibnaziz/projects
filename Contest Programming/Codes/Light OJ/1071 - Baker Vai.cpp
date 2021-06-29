#include <bits/stdc++.h>
using namespace std;
int ar[110][110], m, n;
int dp[110][110][210];
int dirx1[4]={0, 1, 0, 1};
int dirx2[4]={0, 0, 1, 1};
int rec(int x1, int x2, int tot)
{
    int y1=tot-x1, y2=tot-x2;
    //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    if(x1==m || x2==m || y1==n || y2==n)    return -99999;
    if(x1==(m-1) && x2==(m-1) && y1==(n-1) && y2==(n-1))    return  dp[x1][x2][tot]=ar[x1][y1];
    if(dp[x1][x2][tot]!=-1) return dp[x1][x2][tot];
    if(x1==x2 && y1==y2)    return -99999;
    int ans=0;
    for(int i=0; i<4; i++)
    {
        ans=max(ans, ar[x1][y1]+ar[x2][y2]+rec(x1+dirx1[i], x2+dirx2[i], tot+1));
    }
    return dp[x1][x2][tot]=ans;
}

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t<cases)
    {
        scanf("%d %d", &m, &n);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d", &ar[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        int ans=ar[0][0]+rec(1, 0, 1);
        printf("Case %d: %d\n", ++t, ans);
    }

    return 0;
}
