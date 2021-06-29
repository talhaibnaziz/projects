#include <bits/stdc++.h>
using namespace std;

vector <int> tree[10005];
int cnt;
bool vis[10005];

void dfs(int u)
{
    if(vis[u]==1)   return;
    vis[u]=1;
    cnt++;
    for(int i=0; i<tree[u].size(); i++)
    {
        int v=tree[u][i];
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    freopen("out.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m, l;
        scanf("%d %d %d", &n, &m, &l);
        for(int i=0; i<m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            tree[x].push_back(y);
        }
        cnt=0;
        memset(vis, 0, sizeof vis);
        for(int i=0; i<l; i++)
        {
            int d;
            scanf("%d", &d);
            dfs(d);
        }
        printf("%d\n", cnt);
        for(int i=1; i<=n; i++) tree[i].clear();
    }

    return 0;
}
