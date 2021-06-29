#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"I am here\n";
long long par[250], n;

struct edge
{
    long long u, v, w;
    bool operator < (const edge &e) const
    {
        return w<e.w;
    }
};
long long findpar(long long p)
{
    if(par[p]==p)   return p;
    else return par[p]=findpar(par[p]);
}
vector <edge> tree;
vector <edge> ans;
long long mst(long long u, long long v, long long w)
{
    ans.clear();
    edge e;
    e.u=u; e.v=v; e.w=w;
    tree.push_back(e);
    for(long long i=1; i<=n; i++) par[i]=i;
    long long cost=0, cnt=0;
    sort(tree.begin(), tree.end());
    for(long long i=0; i<(int)tree.size(); i++)
    {
        edge e1=tree[i];
        u=findpar(e1.u);
        v=findpar(e1.v);
        if(u!=v)
        {
            cost+=e1.w;
            par[u]=v;
            cnt++;
            ans.push_back(e1);
        }
    }

    if(cnt==(n-1))
    {
        tree=ans;
        return cost;
    }
    else return -1;
}
int main()
{
    //freopen("out.txt", "w", stdout);
    long long cases, t=0;
    scanf("%lld",&cases);
    while(t++<cases)
    {
        long long W, cnt=0;
        scanf("%lld %lld", &n, &W);
        printf("Case %lld:\n", t);
        for(long long i=0; i<W; i++)
        {
            long long u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            long long ans=mst(u, v, w);
            printf("%lld\n", ans);
        }
        tree.clear();
    }

    return 0;
}
