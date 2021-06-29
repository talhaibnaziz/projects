#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, t=0;
    map <string, int> mp;
    vector <int> tree[105];
    int indegree[105]={0};
    string nodes[105];
    while(scanf("%d", &n)==1)
    {
        getchar();
        t++;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            string str;
            cin>>str;
            if(!mp.count(str))
            {
                mp[str]=cnt;
                nodes[cnt]=str;
                cnt++;
            }
        }
        //cout<<cnt<<endl;
        scanf("%d", &m);
        getchar();
        for(int i=0; i<m; i++)
        {
            string u, v;
            cin>>u>>v;
            indegree[mp[v]]++;
            tree[mp[u]].push_back(mp[v]);
        }
        queue <int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                indegree[i]=-1;
                break;
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:", t);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            cout<<' '<<nodes[u];
            for(int i=0; i<tree[u].size(); i++)
            {
                int v=tree[u][i];
                indegree[v]--;
                //printf("(%d %d) ", v, indegree[v]);
            }
            for(int i=0; i<n; i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                    indegree[i]=-1;
                    break;
                }
            }
        }
        printf(".\n\n");
        memset(indegree, 0, sizeof indegree);
        for(int i=0; i<n; i++) tree[i].clear();
        mp.clear();
    }

    return 0;
}
