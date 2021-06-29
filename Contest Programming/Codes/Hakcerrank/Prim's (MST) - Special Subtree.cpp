#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[3005];
struct node
{
    int nxt, wt;
};
struct edge
{
    int u, v, w;
    bool operator<(const edge& e) const
    {
        return w > e.w;
    }
};
vector <node> tree[3005];

int mst(int source)
{
    memset(vis, 0, sizeof vis);
    priority_queue <edge> q;
    edge e; vis[source] = 1;
    e.u = source;
    for(int i=0; i<tree[source].size(); i++)
    {
        e.v = tree[source][i].nxt;
        e.w = tree[source][i].wt;
        q.push(e);
    }
    int cnt = 0, wt=0;
    edge ne;
    while(!q.empty())
    {
        e = q.top();
        q.pop();
        if(vis[e.v])    continue;
        vis[e.v]=1;
        wt+=e.w;
        cnt++;
        if(cnt==n-1)    return wt;

        ne.u = e.v;
        for(int i=0; i<tree[e.v].size(); i++)
        {
            ne.v = tree[e.v][i].nxt;
            ne.w = tree[e.v][i].wt;

            if(!vis[ne.v])
            {
                q.push(ne);
            }
        }
    }
    return wt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        node nodes;
        nodes.nxt = v;
        nodes.wt = w;
        tree[u].push_back(nodes);
        nodes.nxt = u;
        tree[v].push_back(nodes);
    }
    cin>>s;
    cout<<mst(s);

    return 0;
}
