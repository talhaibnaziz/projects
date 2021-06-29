#include <bits/stdc++.h>
using namespace std;

long long b[100005];
long long a[100005];
long long ans[100005];
int level[100005];
bool vis[100005];
vector <int> tree[100005], dfsroots[25];

long long BigMod(long long B, long long P, long long M)
{
    long long R = 1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

long long dfs(int node, int phival, int mod)
{
    if(vis[node])   return a[node];

    mod = phival;
    if(phival==1)   phival=1;
    else if(phival<=2097152) phival/=2;
    else if(phival==1000000007) phival = 1000000006;
    else if(phival==1000000006) phival = 500000002;
    else if(phival==500000002)  phival = 243900800;
    else if(phival==243900800)  phival = 79872000;
    else if(phival==79872000)   phival = 19660800;
    else if(phival==19660800)   phival = 5242880;
    else if(phival==5242880)    phival = 2097152;

    //cout<<"inside "<<node<<' '<<b[node]<<' '<<phival<<endl;

    long long ret = 0;
    vis[node] = 1;
    for(int i=0; i<tree[node].size(); i++)
    {
        ret += BigMod(b[node], dfs(tree[node][i], phival, mod)%phival, mod);
    }

    if(tree[node].size() != 0)    a[node] = ret%mod;
    else    a[node] = b[node]%mod;

    //cout<<"outside "<<node<<' '<<a[node]<<' '<<a[node]<<endl;

    return a[node];
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", &b[i]);
    }
    for(int i=1; i<=k; i++)
    {
        int s;
        scanf("%d", &s);
        for(int j=0; j<s; j++)
        {
            int id;
            scanf("%d", &id);
            level[id] = k;
            dfsroots[i].push_back(id);
        }
    }
    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if(level[u]>level[v])   tree[v].push_back(u);
        else    tree[u].push_back(v);
    }
    for(int i=k; i>=1; i--)
    {
        memset(vis, 0, sizeof vis);
        for(int j=0; j<dfsroots[i].size(); j++)
        {
            dfs(dfsroots[i][j], 1000000007, 1000000007);
            ans[dfsroots[i][j]] = a[dfsroots[i][j]];
        }
    }
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int u;
        scanf("%d", &u);
        printf("%lld\n", ans[u]);
    }

    return 0;
}

/*
1000000007
1000000006
500000002
243900800
79872000
19660800
5242880
2097152
*/
