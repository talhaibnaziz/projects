
#include <bits/stdc++.h>
using namespace std;

struct whole
{
    int u, v, w;
};

struct node
{
    int nxt;
    int cost;
};
vector <whole> sys;
vector <node> g[1005];
int dis[1005], start;
bool vis[1005], found;
vector <int> ans;

void dfs(int u, int cost)
{
    //cout<<u<<' '<<cost<<endl;
    vis[u]=1;
    dis[u]=cost;
    for(int i=0; i<g[u].size(); i++)
    {
        node N=g[u][i];
        int v=N.nxt;
        int w=N.cost;
        if(vis[v])
        {
            if((dis[u]+w)<dis[v])
            {
                found=1;
                start=v;
            }
            return;
        }
        dfs(v, dis[u]+w);
        if(found)   return;
    }
    vis[u]=0;
}

void dfs2(int n)
{
    vis[n]=1;
    ans.push_back(n);
    for(int i=0; i<g[n].size(); i++)
    {
        node N=g[n][i];
        int v=N.nxt;
        if(!vis[v]) dfs2(v);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T=0, cases;
    scanf("%d", &cases);
    while(T++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++)
        {
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            whole w;
            w.u=x; w.v=y; w.w=t;
            sys.push_back(w);
            node N;
            N.nxt=x; N.cost=t;
            g[y].push_back(N);
        }
        for(int i=1; i<n; i++)  dis[i]=9999999;
        dis[0]=0;
        //cout<<"HERE"<<endl;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<sys.size(); j++)
            {
                whole e;
                e=sys[j];
                dis[e.v]=min(dis[e.v], dis[e.u]+e.w);
            }
        }
        //cout<<"HERE"<<endl;
        bool flag=0;
        for(int j=0; j<sys.size(); j++)
        {
            whole e;
            e=sys[j];
            if(dis[e.v]>dis[e.u]+e.w)
            {
                flag=1;
                start=e.v;
                break;
            }
        }
        cout<<start<<endl;
        if(flag)
        {
            memset(vis, 0, sizeof vis);
            memset(dis, 0, sizeof dis);
            found=0;
            dfs(start, 0);
            memset(vis, 0, sizeof vis);
            dfs2(start);
            printf("Case %d:", T);
            sort(ans.begin(), ans.end());
            for(int i=0; i<ans.size(); i++) printf(" %d", ans[i]);
            printf("\n");
        }
        else    printf("Case %d: impossible\n", T);
        sys.clear();
        for(int i=0; i<n; i++)  g[i].clear();
        ans.clear();
    }

    return 0;
}
