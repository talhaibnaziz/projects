#include <bits/stdc++.h>
using namespace std;

struct node
{
    int next;
    int cost;
};

vector <node> tree[5005];
int n, m, t, ans;
int path[5005];
bool flag;

void dfs(int u, int tim, int cnt)
{
    if(tim>t)   return;
    if(u==n)
    {
        ans=max(ans, cnt);
        return;
    }
    for(int i=0; i<tree[u].size(); i++)
    {
        node N=tree[u][i];
        dfs(N.next, tim+N.cost, cnt+1);
    }
}

void dfs2(int u, int tim, int cnt)
{
    if(tim>t)   return;
    if(u==n)
    {
        if(cnt==ans)    flag=1;
        return;
    }
    for(int i=0; i<tree[u].size(); i++)
    {
        node N=tree[u][i];
        dfs2(N.next, tim+N.cost, cnt+1);
        if(flag)
        {
            //cout<<u<<' '<<N.next<<endl;
            path[u]=N.next;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ans=0;
    cin>>n>>m>>t;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        node N;
        N.next=v;
        N.cost=w;
        tree[u].push_back(N);
    }
    dfs(1, 0, 1);
    flag=0;
    dfs2(1, 0, 1);
    cout<<ans<<endl;
    int pos=1;
    while(pos!=n)
    {
        cout<<pos<<' ';
        pos=path[pos];
    }
    cout<<n<<endl;

    return 0;
}
