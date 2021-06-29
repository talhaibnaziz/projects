#include <bits/stdc++.h>
using namespace std;

vector <int> tree[100005];
int c1, c2;
bool vis[100005];
int dis[100005];

int bfs()
{
    int u, v;
    queue <int> q;
    q.push(c1);
    vis[c1]=1; dis[c1]=0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0; i<tree[u].size(); i++)
        {
            v = tree[u][i];
            if(!vis[v])
            {
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
            if(v==c2)   return dis[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cases, t=0, n;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int u, v, s;
            cin>>u>>s;
            for(int j=0; j<s; j++)
            {
                cin>>v;
                tree[u].push_back(v);
            }
        }
        cin>>c1>>c2;
        memset(vis, 0, sizeof vis);
        cout<<c1<<' '<<c2<<' '<<bfs()-1<<'\n';
        if(t<cases) cout<<'\n';
        for(int i=0; i<n; i++)  tree[i].clear();
    }

    return 0;
}
