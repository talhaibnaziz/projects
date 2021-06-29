#include <bits/stdc++.h>
using namespace std;

int links[105];
bool vis[105];

int bfs()
{
    queue <pair<int,int> > q;
    pair <int, int> u, v;
    q.push(make_pair(1,0));
    vis[1]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        //cout<<"position: "<<u.first<<'('<<u.second<<')'<<endl;
        for(int i=1; i<7 && u.first+i<101; i++)
        {
            v.first = u.first+i;
            if(v.first==100)    return u.second+1;
            if(!vis[v.first])
            {
                vis[v.first]=1;
                while(links[v.first]!=-1)   v.first=links[v.first];
                vis[v.first]=1;
                if(v.first==100)    return u.second+1;
                v.second = u.second + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cases,t=0, n, m;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n;
        int u, v;
        memset(links, -1, sizeof links);
        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++)
        {
            cin>>u>>v;
            links[u]=v;
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            links[u]=v;
        }
        int ans = bfs();
        cout<<ans<<"\n";
    }

    return 0;
}
