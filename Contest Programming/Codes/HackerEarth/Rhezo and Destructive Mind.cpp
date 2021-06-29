#include <bits/stdc++.h>
using namespace std;

vector <int> nodes[110];
int low[110], timer, disc[110];
bool arti[110];

void dfs(int node, int par)
{
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
            if(low[next]>=disc[node])   arti[node] = 1;
        }
        else if(par!=next)
        {
            if(disc[next]<disc[node])
            {
                low[node] = min(low[node], low[next]);
                if(low[next]>=disc[node])   arti[node] = 1;
            }
        }
    }
    //cout<<node<<' '<<disc[node]<<' '<<low[node]<<endl;
    if(node == par && child < 2)  arti[node] = 0;
}

int main()
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
    memset(arti, 0, sizeof arti);
    for(int i=1; i<=n; i++)
    {
        if(!disc[i])    dfs(i, i);
    }
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int x;
        scanf("%d", &x);
        if(arti[x]) printf("Satisfied %d\n", nodes[x].size());
        else    printf("Not Satisfied\n");
    }

    return 0;
}
/*
7 7
1 2
1 3
3 4
4 5
4 6
3 7
6 7
7
1
2
3
4
5
6
7
*/
