#include <stdio.h>
#include <vector>
using namespace std;
int visited[100],d[100],f[100],time=0;
 vector <int> graph[100];

 void dfs(int v)
 {
     time=time+1;
     visited[v]=1;
     d[v]=time;
     printf("%d ",v);
     for(int k=0;k<graph[v].size();k++)
     {
         if(visited[graph[v][k]]==0)
         {
             dfs(graph[v][k]);
         }
     }
     visited[v]=2;
     time= time+1;
     f[v]=time;


 }

int main()
{



    int node, edge, x,y,i;
    scanf("%d %d",&node,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
    }

    for(int j=0;j<=node;j++)
    {
        d[j]=-1;
        f[j]=-1;
    }
    for(int k=0;k<=node;k++)
    {
        if(!graph[k].size() && visited[k]==0) dfs(k);
    }

    return 0;
}
