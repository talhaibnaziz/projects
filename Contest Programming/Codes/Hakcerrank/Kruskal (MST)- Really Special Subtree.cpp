#include <bits/stdc++.h>
using namespace std;

int n, m;
struct edge
{
    int u, v, w;
    bool operator<(const edge& e) const
    {
        if(w==e.w)  return (u+v+w) < (e.u+e.v+e.w);
        return w < e.w;
    }
};
int p[3005];
int findpar(int u)
{
    if(p[u]==u) return u;
    return p[u]=findpar(p[u]);
}
vector <edge> edgelist;
int mst()
{
    int s=edgelist.size(), cnt=0, wt=0;
    for(int i=0; i<s; i++)
    {
        if(cnt==(n-1))  break;
        edge e = edgelist[i];
        int upar = findpar(e.u);
        int vpar = findpar(e.v);
        if(upar!=vpar)
        {
            cnt++;
            wt+=e.w;
            p[vpar]=upar;
        }
    }
    return wt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++) p[i]=i;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edge e;
        e.u = u; e.v = v;
        e.w = w;
        edgelist.push_back(e);
    }
    sort(edgelist.begin(), edgelist.end());
    cout<<mst();

    return 0;
}
