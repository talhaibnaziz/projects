#include <bits/stdc++.h>
using namespace std;

string arr[20];
vector <int> tree[20];
int indegree[20], mindegree, n;

bool valid(int src, int des)
{
    queue <int> q;
    q.push(src);
    bool vis[20]={0};
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==des)  return 1;
        for(int i=0; i<tree[u].size(); i++)
        {
            int v = tree[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return 0;
}
void topsort()
{
    priority_queue <int,vector<int>,greater<int> > q;
    for(int i=0; i<n; i++)
    {
        if(indegree[i]==mindegree)
        {
            q.push(i);
            //cout<<'('<<i<<')';
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        cnt++;
        if(cnt!=1)  cout<<' ';
        cout<<u;
        for(int i=0; i<tree[u].size(); i++)
        {
            int v = tree[u][i];
            indegree[v]--;
            if(indegree[v]==0)  q.push(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        cin>>n;
        if(n==0)    break;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            tree[i].clear();
        }
        memset(indegree, 0, sizeof indegree);
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]=='1' && i!=j)
                {
                    if(valid(j,i) && j<i)
                    {
                        cout<<'('<<j<<' '<<i<<')';
                        cnt++;
                        continue;
                    }
                    tree[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
        mindegree=9999;
        for(int i=0; i<n; i++)
        {
            mindegree=min(mindegree,indegree[i]);
        }
        topsort();
        cout<<"\n"<<cnt<<"\n";
    }

    return 0;
}
