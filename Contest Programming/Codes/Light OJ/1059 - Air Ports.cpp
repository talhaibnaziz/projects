#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, cost;
    bool operator<(const edge& c) const
    {
        return cost < c.cost;
    }
};
int n, m, a;
vector <edge> tree;
int par[10010];
int findpar(int p)
{
    if(par[p]==p)   return p;
    else return par[p]=findpar(par[p]);
}
int mst()
{
    long long cost=0;
    int cnt=0;
    for(int i=1; i<=n; i++)  par[i]=i;
    for(int i=0; i<m; i++)
    {
        edge e=tree[i];
        if(cnt==n-1 || e.cost>=a)  break;
        int u=findpar(e.u);
        int v=findpar(e.v);
        if(u!=v)
        {
            cost+=e.cost;
            par[v]=u;
        }
    }

    return cost;
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        scanf("%d %d %d", &n, &m, &a);
        for(int i=0; i<m; i++)
        {
            edge e;
            scanf("%d %d %d", &e.u, &e.v, &e.cost);
            tree.push_back(e);
        }
        sort(tree.begin(), tree.end());
        bool airport[10010];
        memset(airport, 0, sizeof airport);
        long long ans=mst();
        int ap=0;
        for(int i=1; i<=n; i++)
        {
            int city=findpar(i);
            if(!airport[city])
            {
                ans+=a;
                airport[city]=1;
                ap++;
            }
        }
        printf("Case %d: %lld %d\n", t, ans, ap);
        tree.clear();
    }

    return 0;
}
