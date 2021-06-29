#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;
int dis[1005];
int deg[1005];

vector <int> graph[1005];

void topsort(int n)
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {
        if(deg[i]==0)
        {
            q.push(i);
            dis[i]=0;
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //cout<<"queue:  "<<u<<endl;
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            deg[v]--;
            dis[v] = max(dis[v],dis[u]+1);
            if(deg[v]==0)   q.push(v);
        }
    }
}

int main()
{
    freopen("Critical Input.txt", "r", stdin);
    freopen("Critical Output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, tc=0, n, cnt;
    cin>>t;
    while(tc++<t)
    {
        cin>>n;
        cnt = 0;
        mp.clear();
        memset(dis,0,sizeof dis);
        memset(deg,0,sizeof deg);
        for(int i=1; i<=n; i++) graph[i].clear();
        for(int i=0; i<n; i++)
        {
            string task, prev;
            int s;
            cin>>task>>s;
            if(mp[task]==0) mp[task]=++cnt;
            for(int j=0; j<s; j++)
            {
                cin>>prev;
                if(mp[prev]==0) mp[prev]=++cnt;
                int v = mp[task];
                int u = mp[prev];
                graph[u].push_back(v);
                deg[v]++;
                //cout<<"input: ("<<task<<' '<<prev<<")\n";
            }
        }
        topsort(n);
        int query;
        cin>>query;
        cout<<"Case "<<tc<<":\n";
        for(int i=0; i<query; i++)
        {
            string str;
            cin>>str;
            cout<<dis[mp[str]]<<"\n";
            //cout<<mp[str]<<"<--"<<str<<"\n";
        }
    }

    return 0;
}
