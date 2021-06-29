#include <bits/stdc++.h>
using namespace std;
vector <int> nodes[10010];
int low[10010], timer, disc[10010];
int ans;

void dfs(int node, int par)
{
    //cout<<"Entering "<<node<<endl;
    timer++;
    low[node] = timer;
    disc[node] = timer;
    int child = 0;
    for(int i=0; i<nodes[node].size(); i++)
    {
        int next = nodes[node][i];
        if(low[next]==0)
        {
            child++;
            dfs(next, node);
            low[node] = min(low[node], low[next]);
            if(low[next]>disc[node])   ans++;
        }
        else if(par!=next)
        {
            if(disc[next]<disc[node])
            {
                low[node] = min(low[node], disc[next]);
                if(low[next]>disc[node])   ans++;
            }
        }
    }
    //cout<<"Leaving "<<node<<' '<<disc[node]<<' '<<low[node]<<endl;
    //if(node == par && child < 2)  arti[node] = 0;
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }
        timer = 0;
        memset(low, 0, sizeof low);
        memset(disc, 0, sizeof disc);
        ans = 0;
        for(int i=0; i<n; i++)
        {
            if(!disc[i])    dfs(i, i);
        }
        for(int i=0; i<n; i++)
        {
            nodes[i].clear();
        }
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}

