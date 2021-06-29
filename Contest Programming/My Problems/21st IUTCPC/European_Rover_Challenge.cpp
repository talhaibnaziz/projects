#include <bits/stdc++.h>
using namespace std;

vector <pair<double, int> > graph[100005];
double cost[3][100005];

void dijkstra(int node_cnt, int src, int sample)
{
    priority_queue< pair<double, int> > pq;
    pq.push(make_pair(0.0, src));
    cost[sample][src] = 0.0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i].second;
            double w = graph[u][i].first;
            if(cost[sample][v]==-1 || cost[sample][u]+w < cost[sample][v])
            {
                cost[sample][v] = cost[sample][u]+w;
                pq.push(make_pair(-cost[sample][v], v));
            }
        }
    }
}

int main()
{
    freopen("weighted_max_input.txt", "r", stdin);
    freopen("weighted_max_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int tc=0, t, n, m, a, b, c, r;
    cin>>t;
    while(tc++<t)
    {
        cin>>n>>m>>a>>b>>c>>r;
        for(int i=1; i<=n; i++)
        {
            cost[0][i] = -1;
            cost[1][i] = -1;
            cost[2][i] = -1;
            graph[i].clear();
        }
        int u, v; double w;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(make_pair(w, v));
            graph[v].push_back(make_pair(w, u));
        }

        dijkstra(n, a, 0);
        dijkstra(n, b, 1);
        dijkstra(n, c, 2);
        //checking for anomalies
        for(int ch=0; ch<3; ch++)
        {
            if(cost[ch][1]==-1) cout<<"Problem in case: "<<tc<<endl;
            if(cost[ch][a]==-1) cout<<"Problem in case: "<<tc<<endl;
            if(cost[ch][b]==-1) cout<<"Problem in case: "<<tc<<endl;
            if(cost[ch][c]==-1) cout<<"Problem in case: "<<tc<<endl;
            if(cost[ch][r]==-1) cout<<"Problem in case: "<<tc<<endl;
        }
        //source to a to b to c to destination
        double sol = cost[0][1] + cost[0][b] + cost[1][c] + cost[2][r];
        //source to a to c to b to destination
        sol = min(sol, cost[0][1] + cost[0][c] + cost[2][b] + cost[1][r]);
        //source to b to a to c to destination
        sol = min(sol, cost[1][1] + cost[1][a] + cost[0][c] + cost[2][r]);
        //source to b to c to a to destination
        sol = min(sol, cost[1][1] + cost[1][c] + cost[2][a] + cost[0][r]);
        //source to c to a to b to destination
        sol = min(sol, cost[2][1] + cost[2][a] + cost[0][b] + cost[1][r]);
        //source to c to b to a to destination
        sol = min(sol, cost[2][1] + cost[2][b] + cost[1][a] + cost[0][r]);
        cout<<sol<<endl;
    }

    return 0;
}
/*
1
6 5 3 2 5 4
1 2 1
1 3 1
1 4 1
1 5 1
1 6 1
*/
