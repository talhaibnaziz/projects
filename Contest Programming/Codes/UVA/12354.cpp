#include <bits/stdc++.h>
using namespace std;

map <pair<int, int>, bool> mp;
vector <int> tree[20005];
int indegree[20005], outdegree[20005];

int traverse(int node)
{
    //cout<<node<<' ';
    int s = tree[node].size();
    for(int i=0; i<s; i++)
    {
        int nextnode = tree[node][i];
        pair<int, int> p;
        p.first = node;
        p.second = nextnode;
        if(mp[p]==0)
        {
            mp[p]=1;
            outdegree[nextnode]++;
            indegree[node]++;
            int cnt = traverse(nextnode);
            return cnt + 1;
        }
    }
    return 1;
}

int main()
{
    int cases, t=0, n, u, v;
    scanf("%d", &cases);
    while(t++<cases)
    {
        scanf("%d", &n);
        memset(indegree, 0, sizeof indegree);
        memset(outdegree, 0, sizeof outdegree);
        mp.clear();
        for(int i=1; i<n; i++)
        {
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        vector <int> nodes;
        for(int i=0; i<n; i++)  nodes.push_back(i);
        int path = 0;
        int cnt = 0;
        while(cnt<(n-1))
        {
            for(int i=0; i<nodes.size(); i++)
            {
                if(indegree[nodes[i]]!=outdegree[nodes[i]])
                {
                    //cout<<'\n'<<i<<' '<<indegree[i]<<' '<<outdegree[i];
                    //cout<<"\nTRAVERSE: ";
                    int tmpcnt = traverse(nodes[i])-1;
                    cnt+=tmpcnt;
                    if(tmpcnt)  path++;
                    //cout<<"\n"<<cnt;
                    //if(cnt==(n-1))  break;
                }
                else    nodes.erase(nodes.begin()+i);
            }
        }
        for(int i=0; i<n; i++)  tree[i].clear();
        printf("Case %d: %d\n", t, path);
    }

    return 0;
}
