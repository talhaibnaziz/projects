#include <bits/stdc++.h>
using namespace std;

vector <int> nextnode1[2005], nextnode2[2005];
int par1[2005], par2[2005];
bool vis1[2005], vis2[2005];

int findp1(int p)
{
    if(par1[p]!=p)  return par1[p]=findp1(par1[p]);
    return p;
}
int findp2(int p)
{
    if(par2[p]!=p)  return par2[p]=findp2(par2[p]);
    return p;
}
void dfs1(int node)
{
    vis1[node]=1;
    int len = nextnode1[node].size();
    for(int i=0; i<len; i++)
    {
        int v=nextnode1[node][i];
        if(!vis1[v])
        {
            par1[v]=node;
            dfs1(v);
        }
    }
}
void dfs2(int node)
{
    vis2[node]=1;
    int len = nextnode2[node].size();
    for(int i=0; i<len; i++)
    {
        int v=nextnode2[node][i];
        if(!vis2[v])
        {
            par2[v]=node;
            dfs2(v);
        }
    }
}
int main()
{
    int n, m;
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n==0 && m==0)    break;
        int u, v, con;
        memset(vis1, 0, sizeof vis1);
        memset(vis2, 0, sizeof vis2);
        for(int i=1; i<=n; i++)
        {
            par1[i]=i;
            par2[i]=i;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &u, &v, &con);
            nextnode1[u].push_back(v);
            nextnode2[v].push_back(u);
            if(con==2)
            {
                nextnode1[v].push_back(u);
                nextnode2[u].push_back(v);
            }
        }
        dfs1(1);
        dfs2(1);
        int p1=findp1(1), p2=findp2(1);
        bool possible = 1;

        for(int i=2; i<=n; i++)
        {
            int t1=findp1(i), t2=findp2(i);
            if(t1!=p1 || t2!=p2)
            {
                possible = 0;
                break;
            }
        }
        if(possible)    printf("1\n");
        else    printf("0\n");
        for(int i=1; i<=n; i++)
        {
            nextnode1[i].clear();
            nextnode2[i].clear();
        }
    }


    return 0;
}
