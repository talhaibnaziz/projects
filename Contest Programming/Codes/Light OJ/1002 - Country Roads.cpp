#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases, T=0;
    scanf("%d", &cases);
    while(T++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int ar[550][550];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==j)    ar[i][j]=0;
                else ar[i][j]=99999;
            }
        }
        for(int i=0; i<m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            ar[u][v]=min(ar[u][v], w);
            ar[v][u]=min(ar[v][u], w);
        }
        if(m>0)
        {
            for(int k=0; k<n; k++)
            {
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        //cout<<ar[i][j]<<"  ";
                        if(i==j)    continue;
                        ar[i][j]=min(ar[i][j],max(ar[i][k],ar[k][j]));
                    }
                    //cout<<endl;
                }
                //cout<<"\n\n";
            }
        }
        int t;
        scanf("%d", &t);

        printf("Case %d:\n", T);
        for(int i=0; i<n; i++)
        {
            if(ar[t][i]==99999)   printf("Impossible\n");
            else printf("%d\n", ar[t][i]);
        }
    }

    return 0;
}
