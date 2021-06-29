#include <bits/stdc++.h>
using namespace std;

vector <int> graph[20005], rgraph[20005];
vector <pair<int, int> > nodelist;
bool vis[20005];
int start[20005];
int fin[20005];
int cnt;

void dfs(int node)
{
    cnt++;
    vis[node]=1;
    start[node]=cnt;
    cout<<node<<'('<<cnt<<')'<<endl;
    for(int i=0; i<graph[node].size(); i++)
    {
        int nxt = graph[node][i];
        if(!vis[nxt])   dfs(nxt);
    }
    cnt++;
    fin[node]=cnt;
    cout<<node<<'('<<cnt<<')'<<endl;
}
void dfs2(int node)
{
    vis[node]=1;
    cout<<"inside:  "<<node<<endl;
    for(int i=0; i<rgraph[node].size(); i++)
    {
        int nxt = rgraph[node][i];
        if(!vis[nxt])   dfs2(nxt);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int m, n;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
            rgraph[v].push_back(u);
        }
        cnt = 0;
        nodelist.clear();
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=n; i++)
        {
            if(!vis[i]) dfs(i);
            nodelist.push_back(make_pair(fin[i], i));
        }
        sort(nodelist.begin(), nodelist.end());
        memset(vis, 0, sizeof vis);
        cnt = 0;
        for(int i=nodelist.size()-1; i>=0; i--)
        {
            int nxt = nodelist[i].second;
            if(!vis[nxt])
            {
                cnt++;
                dfs2(nxt);
            }
            cout<<"outside: ";
            cout<<nxt<<"(scc "<<cnt<<")\n";
        }
        cout<<"Case "<<t<<": "<<cnt<<"\n";
        for(int i=1; i<=n; i++)
        {
            graph[i].clear();
            rgraph[i].clear();
        }
    }
    return 0;
}

