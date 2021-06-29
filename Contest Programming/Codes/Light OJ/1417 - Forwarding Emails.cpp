#include <bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(0); cin.tie(0);

vector <int> graph[50005], rgraph[50005];
int scc[50005];
int p[50005];
vector <pair<int, int> > nodelist;
bool vis[50005];
int start[50005];
int fin[50005];
int forval[50005];
int cnt;

void dfs(int node)
{
    cnt++;
    vis[node]=1;
    start[node]=cnt;
    //cout<<node<<'('<<cnt<<')'<<endl;
    for(int i=0; i<graph[node].size(); i++)
    {
        int nxt = graph[node][i];
        if(!vis[nxt])   dfs(nxt);
    }
    cnt++;
    fin[node]=cnt;
    //cout<<node<<'('<<cnt<<')'<<endl;
}
void dfs2(int node)
{
    vis[node]=1;
    start[node]=cnt;
    p[cnt]=min(p[cnt], node);
//    cout<<"inside:  "<<node<<"  "<<cnt<<" "<<p[cnt]<<endl;
    for(int i=0; i<rgraph[node].size(); i++)
    {
        int nxt = rgraph[node][i];
        if(!vis[nxt])   dfs2(nxt);
        else if(start[nxt]!=cnt)
        {
            scc[start[nxt]]=cnt;
            //cout<<node<<'('<<cnt<<") - "<<nxt<<"("<<start[nxt]<<")\n";
        }
    }
}

int dfs3(int u)
{
//    cout<<"IN SCC:   "<<u<<endl;
    int v = scc[u];
    vis[u]=1;
    if(v!=0 && !vis[v]) dfs3(v);
    forval[u]+=forval[v];
}

int main()
{
    //fastread
    int t=0, cases;
    cin>>cases;
    int n, u, v;
    while(t++<cases)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
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
        memset(forval, 0, sizeof forval);
        cnt = 0;
        memset(scc, 0, sizeof scc);
        for(int i=nodelist.size()-1; i>=0; i--)
        {
            int nxt = nodelist[i].second;
            if(!vis[nxt])
            {
                cnt++;
                p[cnt]=nxt;
                dfs2(nxt);
            }
            forval[start[nxt]]++;
//            cout<<"outside: ";
//            cout<<nxt<<"(scc "<<start[nxt]<<")\n";
        }
        memset(vis, 0, sizeof vis);
        int ans = 0, ans2;
        for(int i=1; i<=cnt; i++)
        {
            if(!vis[i]) dfs3(i);
            if(ans<forval[i])
            {
                ans = forval[i];
                ans2 = p[i];
            }
            else if(ans==forval[i]) ans2 = min(ans2, p[i]);
//            cout<<"forwarding values:  "<<i<<' '<<forval[i]<<endl;
        }
        cout<<"Case "<<t<<": "<<ans2<<"\n";

        for(int i=1; i<=n; i++)
        {
            graph[i].clear();
            rgraph[i].clear();
        }
    }

    return 0;
}
