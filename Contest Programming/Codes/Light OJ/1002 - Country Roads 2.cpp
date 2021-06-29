#include <bits/stdc++.h>
using namespace std;
int t;
int maxpath[550], cost[550][550];
struct edge
{
    int node;
    int maxcost;
    bool operator<(const edge& rhs) const
    {
        return maxcost < rhs.maxcost;
    }
};
vector <int> tree[510];
void dijkstra()
{
    priority_queue <edge> q;
    edge u;
    u.node=t; u.maxcost=0; maxpath[t]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        //cout<<u.<<node '<<u.maxcost<<endl;
        for(int i=0; i<(int)tree[u.node].size(); i++)
        {
            edge v;
            v.node=tree[u.node][i];
            v.maxcost=max(cost[u.node][v.node], u.maxcost);
            if(v.maxcost<maxpath[v.node])
            {
                maxpath[v.node]=v.maxcost;
                q.push(v);
            }
        }
    }
}
int main()
{
    //freopen("out.txt", "w", stdout);
    int cases, T=0;
    scanf("%d", &cases);
    while(T++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<=n; i++)
        {
            maxpath[i]=30000;
            for(int j=0; j<=n; j++)
            {
                cost[i][j]=30000;
            }
        }
        for(int i=0; i<m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            tree[u].push_back(v);
            tree[v].push_back(u);
            cost[u][v]=min(w, cost[u][v]);
            cost[v][u]=cost[u][v];
        }
        scanf("%d", &t);
        dijkstra();
        printf("Case %d:\n", T);
        for(int i=0; i<n; i++)
        {
            if(maxpath[i]==30000)   printf("Impossible\n");
            else printf("%d\n", maxpath[i]);
            tree[i].clear();
        }
    }

    return 0;
}
