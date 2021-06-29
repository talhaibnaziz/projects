#include <bits/stdc++.h>
using namespace std;

int c[100005];
vector <int> tree[100005];
bool color[100005];
bool vis[100005];

void dfs(int node, int par)
{
    //cout<<"inside: "<<node<<endl;
    vis[node]=1;
    if(c[par]==c[node]) color[node]=color[par];
    else
    {
        if(color[par]) color[node]=0;
        else    color[node]=1;
    }

    for(int i=0; i<tree[node].size(); i++)
    {
        int next = tree[node][i];
        if(!vis[next])   dfs(next, node);
    }
    //cout<<node<<' '<<color[node]<<endl;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1; i<n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);

    color[1] = 0;
    memset(vis, 0,  sizeof vis);
    dfs(1, 1);
    int cnt1=0, cnt0=0;
    int ver0, ver1;
    for(int i=1; i<=n; i++)
    {
        if(color[i]==1)
        {
            cnt1++;
            ver1=i;
        }
        else
        {
            cnt0++;
            ver0=i;
        }
    }
    if(cnt0==0) printf("YES\n%d", ver1);
    else if(cnt1==0)    printf("YES\n%d", ver0);
    else if(cnt0==1)  printf("YES\n%d", ver0);
    else if(cnt1==1)    printf("YES\n%d", ver1);
    else    printf("NO");
    return 0;
}
