#include <bits/stdc++.h>
using namespace std;

vector <int> edge[100010];
int indegree[100010];
map <pair<int, int>, int> edgedir;
vector <pair<int, int> > edges;

void dfs(int node)
{
    bool noeven = 1;
    for(int i=0; i<edge[node].size(); i++)
    {
        int nextnode = edge[node][i];
        if(indegree[nextnode]%2==0)
        {
            pair <int, int> tmp; tmp.first = node; tmp.second = nextnode;
            if(edgedir.count(tmp)==0)  edgedir[tmp]=1;
            else    edgedir[tmp]++;
            //printf("%d %d\n", node, nextnode);
            indegree[node]--;
            indegree[nextnode]--;
            for(int j=0; j<edge[nextnode].size(); j++)
            {
                if(edge[nextnode][j]==node)
                {
                    edge[nextnode].erase(edge[nextnode].begin()+j);
                    break;
                }
            }
            edge[node].erase(edge[node].begin()+i);
            noeven = 0;
            dfs(nextnode);
            break;
        }
    }

    if(noeven && indegree[node]!=0)
    {
        int nextnode = edge[node][0];
        pair <int, int> tmp; tmp.first = node; tmp.second = nextnode;
        if(edgedir.count(tmp)==0)  edgedir[tmp]=1;
        else    edgedir[tmp]++;
        //printf("%d %d\n", node, nextnode);
        indegree[node]--;
        indegree[nextnode]--;
        for(int j=0; j<edge[nextnode].size(); j++)
        {
            if(edge[nextnode][j]==node)
            {
                edge[nextnode].erase(edge[nextnode].begin()+j);
                break;
            }
        }
        edge[node].erase(edge[node].begin()+0);
        dfs(nextnode);
    }
}
int p[100010];
int findpar(int node)
{
    if(p[node]==node)   return node;
    return p[node]=findpar(p[node]);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    memset(indegree, 0, sizeof indegree);
    for(int i=1; i<=n; i++) p[i]=i;
    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        int paru, parv;
        paru = findpar(u);
        parv = findpar(v);
        if(paru!=parv)  p[paru]=parv;
        indegree[u]++;
        indegree[v]++;
        edge[u].push_back(v);
        edge[v].push_back(u);
        pair <int, int> e;
        e.first = u;
        e.second = v;
        edges.push_back(e);
    }
    bool flag = 1;
    for(int i=1; i<=n; i++) if(indegree[i]%2!=0) {flag = 0; break;}
    if(n==1)    flag = 1;
    else
    {
        for(int i=2; i<=n; i++) if(findpar(i)!=findpar(i-1))    {flag = 0; break;}
    }
    if(flag)
    {
        if(n==1)    printf("YES");
        else printf("YES\n");
        for(int i=1; i<=n; i++) dfs(i);
        for(int i=0; i<edges.size(); i++)
        {
            pair <int, int> tmp;
            tmp = edges[i];
            if(edgedir.count(tmp)!=0 && edgedir[tmp]!=0)
            {
                printf("%d %d\n", tmp.first, tmp.second);
                edgedir[tmp]--;
            }
            else
            {
                swap(tmp.first, tmp.second);
                printf("%d %d\n", tmp.first, tmp.second);
                edgedir[tmp]--;
            }
        }
    }
    else printf("NO");

    return 0;
}
