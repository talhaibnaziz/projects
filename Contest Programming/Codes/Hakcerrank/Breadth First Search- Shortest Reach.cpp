#include <bits/stdc++.h>
using namespace std;

vector <int> graph[1005];
int dis[1005];
bool vis[1005];

void bfs(int u)
{
    queue <int> q;
    q.push(u);
    memset(vis, 0, sizeof vis);
    memset(dis, -1, sizeof dis);
    vis[u]=1; dis[u]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
                dis[v]=dis[u]+6;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, t=0;
    cin>>q;
    while(t++<q)
    {
        int n, m, s;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cin>>s;
        bfs(s);
        bool gap = 0;
        for(int i=1; i<=n; i++)
        {
            graph[i].clear();
            if(i!=s)
            {
                if(gap) cout<<' ';
                else    gap = 1;
                cout<<dis[i];
            }
        }
        cout<<"\n";
    }
    return 0;
}
