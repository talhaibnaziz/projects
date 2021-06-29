#include <bits/stdc++.h>

using namespace std;

int a[300005];
vector <int> wire[300005];
vector <int> targetlist;
bool vis[300005];

int findmax(int node, int step, int par)
{
    if(step>2)  return -1000000005;
    //cout<<"inside: "<<node<<' '<<step<<endl;
    int nxt, ret=-1000000005;
    for(int i=0; i<wire[node].size(); i++)
    {
        nxt=wire[node][i];
        if(!vis[nxt] && nxt!=par)
        {
            ret=max(ret, findmax(nxt, step+1, node));
        }
    }
    if(step!=0) ret = max(ret, a[node]);
    return ret;
}
void kickout(int node, int step, int par)
{
    if(step>2)  return;
    a[node]++;
    int nxt;
    for(int i=0; i<wire[node].size(); i++)
    {
        nxt=wire[node][i];
        if(!vis[nxt] && nxt!=par)
        {
            kickout(nxt, step+1, node);
        }
    }
    if(step==0) vis[node]=1;
    else if(step==1)    targetlist.push_back(node);
    return;
}
int main()
{
    int n, u, v;
    memset(vis, 0, sizeof vis);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<n; i++)
    {
        scanf("%d %d", &u, &v);
        wire[u].push_back(v);
        wire[v].push_back(u);
    }
    int target, self=-1000000005, cost=1000000005, tmp, ans;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>self || (a[i]==self && (tmp = findmax(i, 0, 0))<cost))
        {
            target = i;
            cost = tmp;
            self=a[i];
        }
    }
    int nxt;

    ans = a[target];
    //cout<<ans<<' '<<target<<endl;
    kickout(target, 0, 0);
    int todel;
    while(targetlist.size()!=0)
    {
        cost=1000000005;
        self=-1000000005;
        for(int i=0; i<targetlist.size(); i++)
        {
            nxt=targetlist[i];
            if(a[nxt]>self || (a[nxt]==self && (tmp = findmax(i, 0, 0))<cost))
            {
                target = nxt;
                cost = tmp;
                self = a[nxt];
                todel = i;
            }
        }
        targetlist.erase(targetlist.begin()+todel);
        ans = max(ans, a[target]);
        //cout<<ans<<' '<<target<<endl;
        kickout(target, 0, 0);
        //if(ans>10) break;
    }
    printf("%d", ans);

    return 0;
}
