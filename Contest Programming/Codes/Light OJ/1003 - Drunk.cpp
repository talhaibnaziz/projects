#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;
vector <int> graph[10005];
int indegree[10005], n;

void topsort()
{
    queue <int> q;
    for(int i=1; i<=n; i++) if(indegree[i]==0)  q.push(i);
    int u, v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            v=graph[u][i];
            indegree[v]--;
            if(indegree[v]==0)  q.push(v);
        }
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
        int m; n=0;
        cin>>m;
        memset(indegree, 0, sizeof indegree);
        for(int i=0; i<m; i++)
        {
            string a, b;
            cin>>a>>b;
            if(mp[a]==0)   mp[a]=++n;
            if(mp[b]==0)   mp[b]=++n;
            int u=mp[a];
            int v=mp[b];
            graph[u].push_back(v);
            indegree[v]++;
        }
        topsort();
        int yes = 1;
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]!=0)  yes=0;
            graph[i].clear();
        }
        mp.clear();
        if(yes) cout<<"Case "<<t<<": Yes\n";
        else    cout<<"Case "<<t<<": No\n";
    }
    return 0;
}
