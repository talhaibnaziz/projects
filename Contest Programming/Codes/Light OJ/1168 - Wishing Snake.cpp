#include <bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(0); cin.tie(0);

vector <int> graph[1005], rgraph[1005], scc[1005];
vector <pair<int, int> > nodelist;
vector <int> nodes;
bool vis[1005];
int start[1005];
int fin[1005];
int cnt, root, nodecnt;
int edgecnt;

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
    if(node==0) root = cnt;
//    cout<<"inside:  "<<node<<endl;
    for(int i=0; i<rgraph[node].size(); i++)
    {
        int nxt = rgraph[node][i];
        if(!vis[nxt])   dfs2(nxt);
        else if(start[nxt]!=cnt)
        {
            scc[start[nxt]].push_back(cnt);
            edgecnt++;
            //cout<<node<<'('<<cnt<<") - "<<nxt<<"("<<start[nxt]<<")\n";
        }
    }
}

int dfs3(int node)
{
//    cout<<"INSIDE:   "<<node<<endl;
    vis[node]=1;
    int ret = 0;
    for(int i=0; i<scc[node].size(); i++)
    {
        int nxt = scc[node][i];
        if(!vis[nxt])
        {
            ret = 1+dfs3(nxt);
            return ret;
        }
    }
//    cout<<"RETURN with  : "<<ret<<endl;
    return ret;
}
int main()
{
    fastread
//    freopen("out.txt", "w", stdout);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        memset(vis, 0, sizeof vis);
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int k, u, v;
            cin>>k;
            for(int j=0; j<k; j++)
            {
                cin>>u>>v;
                if(!vis[u]) nodes.push_back(u);
                if(!vis[v]) nodes.push_back(v);
                vis[u]=1; vis[v]=1;
                graph[u].push_back(v);
                rgraph[v].push_back(u);
            }
        }
        cnt = 0;
        root = 0;
        nodelist.clear();
        memset(vis, 0, sizeof vis);
        for(int j=0; j< nodes.size(); j++)
        {
            int i=nodes[j];
            if(!vis[i]) dfs(i);
            nodelist.push_back(make_pair(fin[i], i));
        }
        sort(nodelist.begin(), nodelist.end());
        memset(vis, 0, sizeof vis);
        cnt = 0; edgecnt = 0;
        for(int i=nodelist.size()-1; i>=0; i--)
        {
            int nxt = nodelist[i].second;
            if(!vis[nxt])
            {
                cnt++;
                dfs2(nxt);
            }
//            cout<<"outside: ";
//            cout<<nxt<<"(scc "<<start[nxt]<<")\n";
        }
        memset(vis, 0, sizeof vis);
        int ans = 0;
        if(root!=0) ans = dfs3(root);
//        cout<<edgecnt<<' '<<ans<<endl;
        nodecnt=0;
        for(int i=1; i<=cnt; i++)    if(vis[i]) nodecnt++;
//        cout<<"WHAT IS THISS..."<<ans<<' '<<edgecnt<<' '<<nodecnt<<endl;
        if(ans==edgecnt && root!=0 && cnt==nodecnt)    cout<<"Case "<<t<<": YES\n";
        else if(edgecnt==0 && cnt==0)  cout<<"Case "<<t<<": YES\n";
        else    cout<<"Case "<<t<<": NO\n";
        nodes.clear();
        for(int i=0; i<1000; i++)
        {
            graph[i].clear();
            rgraph[i].clear();
            scc[i].clear();
        }
    }

    return 0;
}
/*
2
1
11
0 2
2 1
1 0
3 5
5 4
4 3
6 8
8 7
7 6
3 6
2 3
2
2
1 3
3 2
2
3 2
2 1

*/
