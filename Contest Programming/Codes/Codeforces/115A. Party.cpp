#include <bits/stdc++.h>
using namespace std;

int dis[2005];
vector <int> tree[2005];

int dfs(int node)
{
    cerr<<node<<' '<<dis[node]<<endl;
    int level = 0;
    for(int i=0; i<tree[node].size(); i++)
    {
        int nxt = tree[node][i];
        if(dis[nxt]==-1)    level = max(dfs(nxt), level);
        else    level = max(dis[nxt], level);
    }
    //cout<<'('<<level+1<<')'<<endl;
    return  dis[node] = level+1;
}
int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &m);
        if(m!=-1)    tree[m].push_back(i+1);
    }
    memset(dis, -1, sizeof dis);
    for(int i=1; i<=n; i++)
    {
        if(dis[i]==-1)  dfs(i);
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, dis[i]);
    }
    printf("%d", ans);

    return 0;
}
