#include <bits/stdc++.h>
using namespace std;

int par[120];

struct edge
{
    int u, v, w;
    bool operator<(const edge &e) const
    {
        return w<e.w;
    }
};

int findpar(int p)
{
    if(par[p]==p)   return p;
    else    return par[p]=findpar(par[p]);
}

vector <edge> tree;
vector <string> city;

int mst()
{
    int cost=0;
    sort(tree.begin(), tree.end());
    for(int i=0; i<(int)tree.size(); i++)
    {
        edge e=tree[i];
        int u=findpar(e.u);
        int v=findpar(e.v);
        if(u!=v)
        {
            cost+=e.w;
            par[u]=v;
        }
    }

    return cost;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int m;
        scanf("%d", &m);
        for(int i=0; i<100; i++) par[i]=i;
        for(int i=0; i<m; i++)
        {
            string str1, str2;
            int u, v, w, j;
            cin>>str1>>str2>>w;
            for(j=0; j<(int)city.size(); j++)
            {
                if(city[j]==str1)   break;
            }
            u=j;
            if(j==(int)city.size())  city.push_back(str1);
            for(j=0; j<(int)city.size(); j++)
            {
                if(city[j]==str2)   break;
            }
            v=j;
            if(j==(int)city.size())  city.push_back(str2);
            edge e;
            e.u=u; e.v=v; e.w=w;
            if(w==0)
            {
                u=findpar(u);
                v=findpar(v);
                if(u!=v)  par[u]=v;
            }
            else    tree.push_back(e);
        }
        int ans=mst();
        bool flag=1;
        int p=findpar(0);
        for(int i=1; i<(int)city.size(); i++)
        {
            int c=findpar(i);
            if(c!=p)
            {
                flag=0;
                break;
            }
        }
        if(flag)    printf("Case %d: %d\n", t, ans);
        else printf("Case %d: Impossible\n", t);
        city.clear();
        tree.clear();
    }

    return 0;
}
