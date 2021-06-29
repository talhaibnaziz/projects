#include <bits/stdc++.h>
using namespace std;

#define MX 100

string tasks[1005];
string alpha26[27];
vector <int> graph[1005];
vector <int> input[1005];
bool vis[1005];
bool checked[1005];
map <pair<int, int>, bool> mp;

void dfs(int u)
{
    if(checked[u])  return;
    vis[u]=1;
    checked[u]=1;
    //cout<<u<<endl;
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(vis[v])
        {
            graph[u].erase(graph[u].begin() + i);
            i--; continue;
        }
        dfs(v);
    }
    vis[u]=0;
}

long long RAND()
{
    long long r1 = rand();
    long long r2 = rand();
    long long r3 = rand();
    return r1 * r2 * r3;
}

int main()
{
    freopen("Random Input3.txt","w",stdout);
    srand(time(NULL));
    for(int i=0; i<MX; i++)
    {
        int idx = i%26;
        alpha26[idx].push_back('a'+idx);
        tasks[i] = alpha26[idx];
    }
    cout<<"10\n";
    for(int loop=0; loop<10; loop++)
    {
        memset(vis,0,sizeof vis);
        memset(checked,0,sizeof checked);
        mp.clear();
        for(int i=0; i<MX; i++)
        {
            input[i].clear();
            graph[i].clear();
        }

        long long m=RAND();
        m = m%(2*MX);
        int cnt=0;
        for(long long i=0; i<m; i++)
        {
            int a = rand();
            int b = rand();
            a%=MX; b%=MX;
            if(a==b || mp[make_pair(a,b)]==1 || mp[make_pair(b,a)]==1)  continue;
            mp[make_pair(a,b)]=1;
            graph[a].push_back(b);
            cnt++;
        }
        //cout<<"EDGE COUNT: "<<cnt<<endl;
        for(int i=0; i<MX; i++)
        {
            if(checked[i])  continue;
            //cout<<"dfs:  "<<i<<endl;
            dfs(i);
        }
        for(int i=0; i<MX; i++)
        {
            for(int j=0; j<graph[i].size(); j++)
            {
                int u = i;
                int v = graph[i][j];
                input[v].push_back(u);
            }
        }
        cout<<MX<<"\n";
        for(int i=0; i<MX; i++)
        {
            int s = input[i].size();
            cout<<tasks[i]<<' '<<s;
            for(int j=0; j<s; j++)
            {
                cout<<' '<<tasks[input[i][j]];
            }
            cout<<"\n";
        }
        cout<<"100000\n";
        for(int i=0; i<100000; i++)
        {
            int q = rand();
            q%=MX;
            cout<<tasks[q]<<"\n";
        }
    }

    return 0;
}
