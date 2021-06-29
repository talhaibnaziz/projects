#include <bits/stdc++.h>
using namespace std;

int n, k, x, m, s;
struct mypair
{
    int v, w;
    bool operator<(const mypair& rhs) const
    {
        return w > rhs.w;
    }
};
vector<mypair> roads[100005];
long long dis[100005];

void dijkstra()
{
    mypair u;
    u.v = s;
    u.w = 0;
    dis[u.v] = 0;
    priority_queue <mypair> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        //cout<<u.v<<endl;
        for(int i=0; i<roads[u.v].size(); i++)
        {
            mypair v = roads[u.v][i];
            if(dis[v.v]==-1 || (dis[u.v]+v.w)<dis[v.v])
            {
                dis[v.v] = dis[u.v]+v.w;
                v.w = dis[v.v];
                q.push(v);
                //cout<<"pushing: "<<v.v<<endl;
            }
        }
        if(u.v<=k)
        {
            for(int i=1; i<=k; i++)
            {
                mypair v;
                v.v = i; v.w = x;
                if(dis[v.v]==-1 || (dis[u.v]+v.w)<dis[v.v])
                {
                    dis[v.v] = dis[u.v]+v.w;
                    v.w = dis[v.v];
                    q.push(v);
                    //cout<<"pushing: "<<v.v<<endl;
                }
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
        scanf("%d %d %d %d %d", &n, &k, &x, &m, &s);
        memset(dis, -1, sizeof dis);
        for(int i=0; i<m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            mypair p;
            p.v = v;
            p.w = w;
            roads[u].push_back(p);
            p.v = u;
            roads[v].push_back(p);
        }
        dijkstra();
        for(int i=1; i<=n; i++)
        {
            if(i<n) printf("%lld ", dis[i]);
            else    printf("%lld\n", dis[i]);
            roads[i].clear();
        }
    }


    return 0;
}
