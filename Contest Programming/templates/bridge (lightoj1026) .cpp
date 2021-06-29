#include <bits/stdc++.h>
using namespace std;
 
vector <int> tree[10005];
vector <pair<int, int> > ans;
 
int low[10005], timer, disc[10005];
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first == p2.first)   return p1.second<p2.second;
    return p1.first<p2.first;
}
 
void dfs(int node, int par)
{
    timer++;
    low[node] = timer;
    disc[node] = timer;
    int child = 0;
    for(int i=0; i<tree[node].size(); i++)
    {
        int next = tree[node][i];
        if(low[next]==0)
        {
            child++;
            dfs(next, node);
            low[node] = min(low[node], low[next]);
            if(low[next]>disc[node])
            {
                int u, v;
                u = min(node, next);
                v = max(node, next);
                pair <int, int> p;
                p.first = u;
                p.second = v;
                ans.push_back(p);
            }
        }
        else if(par!=next)
        {
            if(disc[next]<disc[node])
            {
                low[node] = min(low[node], low[next]);
                if(low[next]>disc[node])
                {
                    int u, v;
                    u = min(node, next);
                    v = max(node, next);
                    pair <int, int> p;
                    p.first = u;
                    p.second = v;
                    ans.push_back(p);
                }
            }
        }
    }
    //cout<<node<<' '<<disc[node]<<' '<<low[node]<<endl;
}
 
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            int u, v, k;
            scanf("%d (%d)", &u, &k);
            for(int j=0; j<k; j++)
            {
                scanf("%d", &v);
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
        }
        timer = 0;
        memset(low, 0, sizeof low);
        memset(disc, 0, sizeof disc);
        for(int i=0; i<n; i++)
        {
            if(!disc[i])    dfs(i, i);
        }
        sort(ans.begin(), ans.end(), comp);
        printf("Case %d:\n", t);
        printf("%d critical links\n", ans.size());
        for(int i=0; i<ans.size(); i++) printf("%d - %d\n", ans[i].first, ans[i].second);
        for(int i=0; i<n; i++)  tree[i].clear();
        ans.clear();
    }
 
    return 0;
}