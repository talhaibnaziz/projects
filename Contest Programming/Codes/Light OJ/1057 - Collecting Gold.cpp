#include <bits/stdc++.h>
using namespace std;
int m, n, cnt, chck;
char ar[25][25];
int gold[25][25];
int dis[20][20];
int dp[20][66000];

int rec(int i, int mask)
{
    if(i>0) mask=mask | (1<<(i-1));
    if((chck & mask)==chck) return dis[0][i];
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ret=999;
    for(int loop=1; loop<=cnt; loop++)
    {
        if((mask & (1<<(loop -1)))==0)
        {
            ret = min(ret, dis[i][loop]+rec(loop, mask));
        }
    }

    return dp[i][mask]=ret;
}
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t<cases)
    {
        int x, y;
        cnt=0; chck=0;
        scanf("%d %d", &m, &n);
        getchar();
        memset(gold, -1, sizeof(gold));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%c", &ar[i][j]);
                if(ar[i][j]=='x')
                {
                    gold[i][j]=0;
                    x=i;
                    y=j;
                }
                else if(ar[i][j]=='g')
                {
                    chck=chck | (1<<cnt);
                    cnt++;
                    gold[i][j]=cnt;
                }
            }
            getchar();
        }
        for(int i1=0; i1<m; i1++)
        {
            for(int j1=0; j1<n; j1++)
            {
                for(int i2=0; i2<m; i2++)
                {
                    for(int j2=0; j2<n; j2++)
                    {
                        if(gold[i1][j1]!=-1 && gold[i2][j2]!=-1)
                        {
                            int g1=gold[i1][j1], g2=gold[i2][j2];
                            dis[g1][g2]=abs(i1-i2)+abs(j1-j2)-min(abs(i1-i2), abs(j1-j2));
                            dis[g2][g1]=dis[g1][g2];
                        }
                    }
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        //cout<<chck<<endl;
        printf("Case %d: %d\n", ++t, rec(0, 0));
    }

    return 0;
}
