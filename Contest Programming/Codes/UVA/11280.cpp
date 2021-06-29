#include <bits/stdc++.h>
using namespace std;

string cities[105];
map <string, int> mp;
int cost[105][105];
int dis[105];
struct edge
{
    int u, v, w;
    bool operator<(const edge& rhs) const
    {
        return v > rhs.v;
    }
};
vector <edge> flights;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int n, m;
        cin>>n;
        //getchar();
        for(int i=0; i<n; i++)
        {
            cin>>cities[i];
            mp[cities[i]]=i;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cost[i][j]=9999999;
            }
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            string u, v;
            int w;
            cin>>u>>v>>w;
            edge e;
            e.u=mp[u]; e.v=mp[v]; e.w=w;
            flights.push_back(e);
        }
        sort(flights.begin(), flights.end());
        int q;
        cin>>q;
        cout<<"Scenario #"<<t<<"\n";
        for(int i=0; i<q; i++)
        {
            for(int j=1; j<n; j++)  dis[j]=9999999;
            dis[0]=0;
            int e;
            cin>>e;
            for(int j=0; j<=e; j++)
            {
                for(int k=0; k<flights.size(); k++)
                {
                    edge f=flights[k];
                    dis[f.v]=min(dis[f.v], dis[f.u]+f.w);
                }
            }
            if(dis[n-1]<9999999)    cout<<"Total cost of flight(s) is $"<<dis[n-1]<<"\n";
            else    cout<<"No satisfactory flights\n";
        }
        if(t!=cases)    cout<<"\n";
        mp.clear();
        flights.clear();
    }

    return 0;
}
