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
struct node
{
    long long n, cost;
};

vector <edge> arr;
vector <node> tree[210];

long long findpar(long long p)
{
    if(par[p]==p)   return p;
    else return par[p]=findpar(par[p]);
}

long long mst()
{
    long long ans=0, cnt=0;
    for(long long i=1; i<=n; i++) par[i]=i;
    sort(arr.begin(), arr.end());
    for(long long i=0; i<(int)arr.size(); i++)
    {
        edge e=arr[i];
        long long u=findpar(e.u);
        long long v=findpar(e.v);
        if(u!=v)
        {
            cnt++;
            ans+=e.w;
            par[u]=v;
            node n;
            n.n=e.v; n.cost=e.w;
            tree[e.u].push_back(n);
            n.n=e.u;
            tree[e.v].push_back(n);
        }
        if(cnt==n)  break;
    }

    return ans;
}
long long maxu, maxv;
bool vis[210];
long long dfs(long long u, long long maxcost, long long v, long long ansu, long long ansv)
{
    //cout<<u<<' '<<maxcost<<endl;
    if(u==v)
    {
        maxu=ansu; maxv=ansv;
        return maxcost;
    }
    vis[u]=1;
    long long ans=0;
    for(long long i=0; i<(int)tree[u].size(); i++)
    {
        if(vis[tree[u][i].n])   continue;
        if(tree[u][i].cost>maxcost)
        {
            maxcost=tree[u][i].cost;
            ansu=u; ansv=tree[u][i].n;
        }
        ans=max(ans, dfs(tree[u][i].n,maxcost, v, ansu, ansv));
    }
    return ans;
}
long long updatecost(long long u, long long v, long long w)
{
    //cout<<"Update\n";
    for(long long i=0; i<(int)tree[u].size(); i++)
    {
        node n=tree[u][i];
        //cout<<n.n<<' '<<n.cost<<endl;
        if(n.n==v)
        {
            if(n.cost>w)
            {
                tree[u][i].cost=w;
                for(long long i=0; i<(int)tree[v].size(); i++)
                {
                    node n1=tree[v][i];
                    if(n1.n==u)
                    {
                        //cout<<"Changed edge\n";
                        tree[v][i].cost=w;
                        //cout<<tree[v][i].cost<<endl;
                        break;
                    }
                }
                return w-n.cost;
            }
            else return 0;
        }
    }
    memset(vis, 0, sizeof vis);
    long long maxcost=dfs(u, 0, v, u, v);
    //debug
    if(maxcost>w)
    {
        for(long long i=0; (int)tree[maxu].size(); i++)
        {
            if(tree[maxu][i].n==maxv)
            {
                tree[maxu].erase(tree[maxu].begin()+i);
                break;
            }
        }
        for(long long i=0; (int)tree[maxv].size(); i++)
        {
            if(tree[maxv][i].n==maxu)
            {
                tree[maxv].erase(tree[maxv].begin()+i);
                break;
            }
        }
        node n;
        n.n=v; n.cost=w;
        tree[u].push_back(n);
        n.n=u;
        tree[v].push_back(n);
        return w-maxcost;
    }
    return 0;
}
int main()
{
    freopen("out.txt", "w", stdout);
    long long cases, t=0;
    scanf("%lld",&cases);
    while(t++<cases)
    {
        long long W, cnt=0;
        scanf("%lld %lld", &n, &W);
        for(long long i=1; i<=n; i++) par[i]=i;
        printf("Case %lld:\n", t);
        for(long long i=0; i<W; i++)
        {
            long long u, v, w, ans;
            scanf("%lld %lld %lld", &u, &v, &w);
            if(cnt<(n-1))
            {
                edge e;
                e.u=u; e.v=v; e.w=w;
                arr.push_back(e);
                long long upar=findpar(u);
                long long vpar=findpar(v);
                if(upar!=vpar)
                {
                    par[upar]=vpar;
                    cnt++;
                }
                if(cnt<(n-1))   printf("-1\n");
            }
            if(cnt==(n-1))
            {
                ans=mst();
                printf("%lld\n", ans);
                cnt++;
            }
            else if(cnt>(n-1))
            {
                ans+=updatecost(u, v, w);
                printf("%lld\n", ans);
            }
        }
        for(long long i=1; i<=n; i++) tree[i].clear();
        arr.clear();
    }

    return 0;
}
