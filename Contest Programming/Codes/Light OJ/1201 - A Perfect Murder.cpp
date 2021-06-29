#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> tree[1010];
bool vis[1010], vis2[1010];
int dp[1010][3];
int rec(int node, bool ik)
{
    if(dp[node][ik]!=-1)    return dp[node][ik];
    vis[node]=1;
    vis2[node]=1;
    //cout<<node<<' '<<ik<<endl;
    int ans=0;
    if(ik)
    {
        ans++;
        for(int i=0; i<(int)tree[node].size(); i++)
        {
            if(!vis[tree[node][i]]) ans+=rec(tree[node][i], 0);
        }
    }
    else
    {
        for(int i=0; i<(int)tree[node].size(); i++)
        {
            if(!vis[tree[node][i]]) ans+=max(rec(tree[node][i], 0), rec(tree[node][i], 1));
        }
    }
    //cout<<ans<<endl;
    vis[node]=0;
    return dp[node][ik]=ans;
}
int main()
{
    int cases, t=0;
    cin>>cases;
    while(t<cases)
    {
        int m;
        for(int i=0; i<1005; i++)   tree[i].clear();
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            int u, v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        memset(vis2, 0, sizeof(vis2));
        memset(dp, -1, sizeof(dp));
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(!vis2[i]) ans+=max(rec(i, 0), rec(i, 1));
        }
        cout<<"Case "<<++t<<": "<<ans<<"\n";
    }

    return 0;
}
