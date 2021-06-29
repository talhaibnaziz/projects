#include <bits/stdc++.h>
using namespace std;

struct node
{
    int next;
    int cost;
    bool built;
    int proposed;
    bool operator < (const node &N) const
    {
        return cost>N.cost;
    }
};

vector <node> tree[10010];
int d, n;
int dis[15][10010];
void dijkstra()
{
    priority_queue <node> q;
    node N;
    N.next=0; N.cost=0; N.built=1; N.proposed=0;
    q.push(N);
    for(int j=0; j<=d; j++)
        for(int i=0; i<n; i++)  dis[j][i]=99999999;
    dis[0][0]=0;
    while(!q.empty())
    {
        node u=q.top();
        q.pop();
        //cout<<u.next<<' '<<u.built<<' '<<u.proposed<<endl;
        for(int i=0; i<(int)tree[u.next].size(); i++)
        {
            node v=tree[u.next][i];
            if(!v.built) v.proposed=u.proposed+1;
            else v.proposed=u.proposed;
            if(v.proposed<=d && (dis[u.proposed][u.next]+v.cost)<dis[v.proposed][v.next])
            {
                dis[v.proposed][v.next]=dis[u.proposed][u.next]+v.cost;
                q.push(v);
            }
        }
    }
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int m, k;
        scanf("%d %d %d %d", &n, &m, &k, &d);
        for(int i=0; i<m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            node N;
            N.next=v; N.cost=w; N.built=1;
            tree[u].push_back(N);
        }
        for(int i=0; i<k; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            node N;
            N.next=v; N.cost=w; N.built=0;
            tree[u].push_back(N);
        }
        dijkstra();
        int ans=99999999;
        for(int i=0; i<=d; i++) ans=min(ans, dis[i][n-1]);
        if(ans==99999999)  printf("Case %d: Impossible\n", t);
        else printf("Case %d: %d\n", t, ans);
        for(int i=0; i<n; i++)  tree[i].clear();
    }

    return 0;
}
