#include <bits/stdc++.h>
using namespace std;

vector <int> tree[100005];
int tim;
bool vis[100005];
struct nodes
{
    int ser, s, f;
    bool operator<(const nodes& n) const
    {
        return f > n.f;
    }
}d[100005];

void dfs(int u)
{
    d[u].s=tim;
    for(int i=0; i<tree[u].size(); i++)
    {
        int v=tree[u][i];
        if(d[v].s==0)
        {
            tim++;
            dfs(v);
        }
    }
    tim++;
    d[u].f=tim;
}
void dfs2(int u)
{
    vis[u]=1;
    for(int i=0; i<tree[u].size(); i++)
    {
        int v=tree[u][i];
        if(!vis[v]) dfs2(v);
    }
}
int main()
{
    //freopen("out.txt", "w", stdout);
    //freopen("in.txt", "r", stdin);
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
        }
        for(int i=1; i<=n; i++)
        {
            d[i].s=0;
            d[i].ser=i;
        }
        int cnt=0, tim=1;
        for(int i=1; i<=n; i++)
        {
            if(d[i].s==0)
            {
                dfs(i);
            }
        }
        sort(d+1, d+n+1);
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=n; i++)
        {
            if(!vis[d[i].ser])
            {
                cnt++;
                dfs2(d[i].ser);
            }
        }
        printf("%d\n", cnt);
        for(int i=1; i<=n; i++) tree[i].clear();
    }

    return 0;
}
