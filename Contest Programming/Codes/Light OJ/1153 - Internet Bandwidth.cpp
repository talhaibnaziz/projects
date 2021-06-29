#include <bits/stdc++.h>
using namespace std;

int n, s, t, c;
int b[110][110];
int minflow[110];
bool vis[110];
int parent[110];
int cnt =0;

int maxflow(int node)
{
    int u;
    int flow = 0;
    minflow[t] = 0;
    queue <int> q;
    while(1)
    {
        q.push(node);
        minflow[node] = 99999999;
        memset(vis, 0, sizeof vis);
        cnt++;
        vis[node] = 1;
        while(!q.empty())
        {
            u=q.front();
            if(u==t)
            {
                flow += minflow[t];
                while(!q.empty())   q.pop();
                break;
            }
            //cout<<parent[u]<<' '<<u<<' '<<minflow[u]<<endl;
            q.pop();
            for(int i=1; i<=n; i++)
            {
                if(b[u][i]>0 && !vis[i])
                {
                    q.push(i);
                    minflow[i]=min(minflow[u], b[u][i]);
                    parent[i]=u;
                    vis[i] = 1;
                }
            }
        }
        if(u!=t)    break;
        else
        {
            int v=t;
            while(v!=s)
            {
                //cout<<v<<endl;
                u = parent[v];
                b[u][v] -= minflow[t];
                b[v][u] += minflow[t];
                v = u;
            }
        }
    }
    return flow;
}
int main()
{
    int T=0, cases;
    scanf("%d", &cases);
    while(T++<cases)
    {
        scanf("%d", &n);

        memset(b, 0, sizeof b);
        memset(vis, 0, sizeof vis);

        scanf("%d %d %d", &s, &t, &c);
        for(int i=0; i<c; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            b[u][v]+=w;
            b[v][u]+=w;
        }
        int ans;
        ans = maxflow(s);
        printf("Case %d: %d\n", T, ans);
    }

    return 0;
}
