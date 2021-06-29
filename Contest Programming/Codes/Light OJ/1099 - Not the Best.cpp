#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int node;
    int cost;
    bool operator<(const edge& e) const
    {
        return cost < e.cost;
    }
};

int dis1[5010], dis2[5010];

vector <edge> tree[5010];

void dijkstra()
{
    priority_queue <edge> q;
    edge e1;
    e1.node=1; e1.cost=0; dis1[1]=0;
    q.push(e1);
    while(!q.empty())
    {
        e1=q.top();
        q.pop();
        //cout<<e1.node<<' '<<dis1[e1.node]<<' '<<dis2[e1.node]<<endl;
        for(int i=0; i<tree[e1.node].size(); i++)
        {
            edge e2=tree[e1.node][i];
            if((dis1[e1.node]+e2.cost)<dis1[e2.node])
            {
                dis2[e2.node]=dis1[e2.node];
                dis1[e2.node]=dis1[e1.node]+e2.cost;
                q.push(e2);
            }
            else if((dis1[e1.node]+e2.cost)<dis2[e2.node] && (dis1[e1.node]+e2.cost)!=dis1[e2.node])
            {
                dis2[e2.node]=dis1[e1.node]+e2.cost;
                q.push(e2);
            }
            else if((dis2[e1.node]+e2.cost)<dis2[e2.node])
            {
                dis2[e2.node]=dis2[e1.node]+e2.cost;
                q.push(e2);
            }
        }
    }
}
int main()
{
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int n, r;
        cin>>n>>r;
        for(int i=1; i<=n; i++)
        {
            tree[i].clear();
            dis1[i]=9999999;
            dis2[i]=9999999;
        }
        for(int i=0; i<r; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            edge e;
            e.node=v; e.cost=w;
            tree[u].push_back(e);
            e.node=u;
            tree[v].push_back(e);
        }
        dijkstra();
        printf("Case %d: %d\n", t, dis2[n]);
    }

    return 0;
}
