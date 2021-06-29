#include <bits/stdc++.h>
using namespace std;

vector <int> tree[100005];
double ans;

void dfs(int node, double p, int par, double len)
{
    //cout<<node<<p<<endl;
    int s = tree[node].size();
    if(s==1 && tree[node][0]==par)  ans += p*len;
    for(int i=0; i<s; i++)
    {
        if(tree[node][i]==par)  continue;
        if(node!=1) dfs(tree[node][i], p/((double)(s-1)), node, len+1);
        else    dfs(tree[node][i], p/((double)s), node, len+1);
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n, u, v;
    cin>>n;
    for(int i=0; i<(n-1); i++)
    {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 1.00, 1, 0);
    printf("%.7f", ans);

    return 0;
}
