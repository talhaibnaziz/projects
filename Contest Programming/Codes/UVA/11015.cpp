#include <bits/stdc++.h>
using namespace std;

string names[25];
int ar[25][25];

int main()
{
    freopen("out.txt", "w", stdout);
    int n, m, t=0;
    while(++t)
    {
        scanf("%d %d", &n, &m);
        getchar();
        if(n==0 && m==0)    break;
        for(int i=0; i<n; i++)  cin>>names[i];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                ar[i][j]=999999;
                if(i==j)    ar[i][j]=0;
            }
        }
        for(int i=0; i<m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            ar[u][v]=w;
            ar[v][u]=w;
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    ar[i][j]=min(ar[i][j], ar[i][k]+ar[k][j]);
                }
            }
        }
        int ans=999999;
        int sum[25];
        memset(sum, 0, sizeof sum);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                sum[i]+=ar[j][i];
            }
            ans=min(ans, sum[i]);
        }
        for(int i=1; i<=n; i++)
        {
            if(ans==sum[i])
            {
                printf("Case #%d : ", t);
                cout<<names[i-1]<<"\n";
                break;
            }
        }
    }

    return 0;
}
