#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;

int edge[600][600], src, sink, n;
bool vis[600];

int maxflow(int node, int min_cap)
{
    if(node==sink)  return min_cap;
    vis[node]=1;
    //cout<<"entering: "<<node<<' '<<min_cap<<endl;
    int ret = 0, flow;
    while(1)
    {
        flow = 0;
        for(int i=1; i<=sink; i++)
        {
            //if(edge[node][i]>0) cout<<"edge here -> "<<i<<endl;
            if(!vis[i] && edge[node][i]>0)
            {
                flow = min(min_cap, edge[node][i]);
                flow = maxflow(i, flow);
                edge[node][i] -= flow;
                edge[i][node] += flow;
                min_cap -= flow;
                ret +=flow;
            }
        }
        if(flow==0) break;
    }
    //cout<<"exiting "<<node<<" with value: "<<ret<<endl;
    vis[node]=0;
    return ret;
}

int main()
{
    mp["XXL"]=1, mp["XL"]=2, mp["L"]=3, mp["M"]=4, mp["S"]=5, mp["XS"]=6;
    int t = 0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int m; sink = 550; src = 0;
        string a, b;
        cin>>n>>m;
        memset(edge, 0, sizeof edge);
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=6; i++)  edge[src][i] = n;

        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            edge[mp[a]][i*10] = 1;
            edge[mp[b]][i*10] = 1;
            edge[i*10][sink] = 1;
        }

        int ans=maxflow(src, 99999999);
        if(ans == m)    printf("Case %d: YES\n", t);
        else    printf("Case %d: NO\n", t);
    }

    return 0;
}
/*
2 6
XL L
XL L
XL L
XL S
XL S
XL S
*/
