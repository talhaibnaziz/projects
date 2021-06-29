#include <bits/stdc++.h>
using namespace std;

struct whole
{
    int u, v, w;
};
vector <whole> sys;
int dis[1005];

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int n, m;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            int x, y, t;
            cin>>x>>y>>t;
            whole w;
            w.u=x; w.v=y; w.w=t;
            sys.push_back(w);
        }
        for(int i=1; i<n; i++)  dis[i]=9999999;
        dis[0]=0;
        //cout<<"HERE"<<endl;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<sys.size(); j++)
            {
                whole e;
                e=sys[j];
                dis[e.v]=min(dis[e.v], dis[e.u]+e.w);
            }
        }
        //cout<<"HERE"<<endl;
        bool flag=0;
        for(int j=0; j<sys.size(); j++)
        {
            whole e;
            e=sys[j];
            if(dis[e.v]>dis[e.u]+e.w)
            {
                flag=1;
                break;
            }
        }
        if(flag)    cout<<"possible\n";
        else    cout<<"not possible\n";
        sys.clear();
    }

    return 0;
}
