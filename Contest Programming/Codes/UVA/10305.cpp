#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> tree[105];
    int indegree[105]={0};
    int n, m;
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n==0 && m==0)    break;
        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            indegree[v]++;
            tree[u].push_back(v);
        }
        queue <int> q;
        for(int i=1; i<=n; i++) if(indegree[i]==0)  q.push(i);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            printf("%d ", u);
            for(int i=0; i<tree[u].size(); i++)
            {
                int v=tree[u][i];
                indegree[v]--;
                //printf("(%d %d) ", v, indegree[v]);
                if(indegree[v]==0)  q.push(v);
            }
        }
        printf("\n");
        memset(indegree, 0, sizeof indegree);
        for(int i=1; i<=n; i++) tree[i].clear();
    }

    return 0;
}
