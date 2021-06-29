#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    cin>>cases;
    while(t++<cases)
    {
        int n, m;
        int ar[110][110];
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                ar[i][j]=9999999;
            }
        }
        for(int i=0; i<m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            ar[u][v]=min(w, ar[u][v]);
            ar[v][u]=ar[u][v];
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
        if(ar[1][n]==9999999)   printf("Case %d: Impossible\n", t);
        else printf("Case %d: %d\n", t, ar[1][n]);
    }

    return 0;
}
