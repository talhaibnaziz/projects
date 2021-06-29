#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int node;
    int cost;
};
struct path
{
    int node;
    int dis;
    bool operator<(const path& p) const
    {
        return dis < p.dis;
    }
};
int n, m;
int dis[100010], nxt[100010];
vector <edge> tree[100010];
int dijkstra()
{
    priority_queue <path> q;
    path u;
    u.node=1; u.dis=0; dis[1]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        cout<<u.node<<' '<<u.dis<<endl;
        for(int i=0; i<(int)tree[u.node].size(); i++)
        {
            edge e=tree[u.node][i];
            if(dis[e.node]==-1 || dis[u.node]+e.cost<dis[e.node])
            {
                dis[e.node]=dis[u.node]+e.cost;
                nxt[u.node]=e.node;
                path p;
                p.node=e.node;
                p.dis=dis[e.node];
                q.push(p);
            }
        }
    }

    return dis[n];
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edge e;
        e.node=v; e.cost=w;
        tree[u].push_back(e);
        e.node=u;
        tree[v].push_back(e);
    }
    memset(dis, -1, sizeof(dis));
    int ans=dijkstra();
    int node=1;
    if(ans==-1) cout<<"-1";
    else
    {
        while(1)
        {
            if(node==n)
            {
                cout<<node;
                break;
            }
            cout<<node<<' ';
            node=nxt[node];
        }
    }


    return 0;
}
