#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

vector <int> p[100005];
bool vis[100005];

int dfs(int u)
{
    vis[u]=1;
    int ret = 1;
    for(int i=0; i<p[u].size(); i++)    if(!vis[p[u][i]]) ret+=dfs(p[u][i]);
    return ret;
}
int main()
{
    int n,l;
    scanf("%d %d",&n,&l);
    memset(vis, 0, sizeof vis);
    if(n==1)
    {
        printf("0\n");
        return(0);
    }


    long long int ans=0, sum=0, tmp;

    /** Write code to compute answer using n,l,pairs**/
    for(int i=0; i<l; i++)
    {
        int u, v;
        scanf("%d %d",&u,&v);
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            tmp = dfs(i);
            ans += sum*tmp;
            sum += tmp;
            //cout<<i<<": "<<tmp<<' '<<ans<<endl;
        }
    }
    printf("%lld\n",ans);
    return(0);
}
