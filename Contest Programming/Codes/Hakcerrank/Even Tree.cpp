#include <bits/stdc++.h>
using namespace std;

vector <int> tree[105];
vector <pair<int,int> > edges;
int nodecount[105][105];
bool vis[105];
int n;

int dfs(int u)
{
    vis[u]=1;
    int ret = 1;
    for(int i=0; i<tree[u].size(); i++)
    {
        int v = tree[u][i];
        if(vis[v])  continue;
        int cnt = dfs(v);
        ret += cnt;
        nodecount[u][v]=cnt%2;
        nodecount[v][u]=(n-cnt)%2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    memset(vis, 0, sizeof vis);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges.push_back(make_pair(u,v));
    }
    int a=dfs(1);
    int ans=0;
    for(int i=0; i<m; i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        if(nodecount[u][v]==0 && nodecount[v][u]==0)
        {
            //cout<<u<<' '<<v<<endl;
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
