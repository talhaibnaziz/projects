#include <bits/stdc++.h>
using namespace std;

vector <int> tree[105];
bool vis[105];
int cnt;
void dfs(int u)
{
    for(int i=0; i<tree[u].size(); i++)
    {
        int v=tree[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            cnt++;
            dfs(v);
        }
    }
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(n==0)    break;
        while(1)
        {
            int u;
            scanf("%d", &u);
            if(u==0)    break;
            while(1)
            {
                int v;
                scanf("%d", &v);
                if(v==0)    break;
                tree[u].push_back(v);
            }
        }
        int m;
        scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            int start;
            memset(vis, 0, sizeof vis);
            cnt=0;
            scanf("%d", &start);
            dfs(start);
            int ans;
            ans=n-cnt;
            //if(ans<0)   ans=0;
            printf("%d", ans);
            for(int i=1; i<=n; i++) if(!vis[i]) printf(" %d", i);
            printf("\n");
        }
        for(int i=1; i<=n; i++) tree[i].clear();
    }

    return 0;
}
