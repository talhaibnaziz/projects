#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"I am here"<<endl

int N, M, s, t, p;
struct node
{
    int to;
    int cost;
    bool operator < (const node &n) const
    {
        return cost<n.cost;
    }
};
struct edge
{
    int u, v, w;
    bool operator < (const edge &e) const
    {
        return w>e.w;
    }
};

vector <node> tree[10010];
vector <node> treerev[10010];
vector <edge> msttree;

int main()
{
    int cases, T=0;
    scanf("%d", &cases);
    while(T++<cases)
    {
        scanf("%d %d %d %d %d", &N, &M, &s, &t, &p);
        for(int i=0; i<M; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            node n;
            n.to=v; n.cost=w;
            tree[u].push_back(n);
            n.to=u;
            treerev[v].push_back(n);
            edge e;
            e.u=u; e.v=v; e.w=w;
            msttree.push_back(e);
        }
        sort(msttree.begin(), msttree.end());
        int dis1[10010], dis2[10010];
        for(int i=1; i<=N; i++)
        {
            dis1[i]=99999999;
            dis2[i]=99999999;
        }
        priority_queue <node> q;
        node n;
        n.to=s;
        n.cost=0;
        dis1[s]=0;
        q.push(n);
        while(!q.empty())
        {
            n=q.top();
            q.pop();
            for(int i=0; i<(int)tree[n.to].size(); i++)
            {
                node next=tree[n.to][i];
                if((dis1[n.to]+next.cost)<dis1[next.to])
                {
                    dis1[next.to]=dis1[n.to]+next.cost;
                    q.push(next);
                }
            }
        }
        n.to=t;
        n.cost=0;
        dis2[t]=0;
        q.push(n);
        while(!q.empty())
        {
            n=q.top();
            q.pop();
            for(int i=0; i<(int)treerev[n.to].size(); i++)
            {
                node next=treerev[n.to][i];
                if((dis2[n.to]+next.cost)<dis2[next.to])
                {
                    dis2[next.to]=dis2[n.to]+next.cost;
                    q.push(next);
                }
            }
        }
        int ans=-1;
        for(int i=0; i<(int)msttree.size(); i++)
        {
            edge e=msttree[i];
            if((dis1[e.u]+dis2[e.v]+e.w)<=p)
            {
                //cout<<e.u<<": "<<dis1[e.u]<<' '<<e.v<<": "<<dis2[e.v]<<' '<<p<<endl;
                ans=e.w;
                break;
            }
        }
        printf("Case %d: %d\n", T, ans);
        for(int i=1; i<=N; i++)
        {
            tree[i].clear();
            treerev[i].clear();
        }
        msttree.clear();
    }

    return 0;
}
