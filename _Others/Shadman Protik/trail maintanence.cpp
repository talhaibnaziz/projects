#include<bits/stdc++.h>
using namespace std;
int n;
struct edge
{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};
vector<edge> e,mv;
int pr[210];
int find(int r)
{
   return (pr[r]==r) ? r:  pr[r]=find(pr[r]);
}
int mst(edge tmp)
{
    e.push_back(tmp);
    edge tt;
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++)pr[i]=i;

    int count=0,s=0;
    for(int i=0;i<(int)e.size();i++)
    {
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            pr[u]=v;
            count++;
            s+=e[i].w;
            tt=e[i];
            mv.push_back(tt);
            if(count==n-1) break;
        }
    }
    if(count<(n-1)) return -1;
    else{
        e.clear();
        for(int i=0;i<mv.size();i++){
            e.push_back(mv[i]);
        }
        mv.clear();
        return s;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        e.clear();
        mv.clear();
        printf("Case %d:\n",tc);
        int weeks;
        edge temp;
        scanf("%d %d",&n,&weeks);
        for(int i=0;i<weeks;i++){
            scanf("%d %d %d",&temp.u,&temp.v,&temp.w);
            printf("%d\n",mst(temp));
        }
    }
}
