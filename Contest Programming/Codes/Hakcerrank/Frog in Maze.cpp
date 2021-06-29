#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

char arr[25][25];
bool vis[25][25];
int tunnel[400][4], n, m;
map <pair<int, int>, bool> mp;
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};

struct node
{
    int x;
    int y;
    double prob;
};

double bfs(int x, int y, int k)
{
    node u, v;
    double ways;
    u.x = x;
    u.y = y;
    u.prob = 1;
    memset(vis, 0, sizeof vis);
    queue <node> q;
    q.push(u);
    vis[x][y]=1;
    double ans = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        //cout<<u.x<<' '<<u.y<<' '<<u.prob<<endl;
        if(arr[u.x][u.y]=='%')
        {
            ans += u.prob;
            continue;
        }
        ways = 0;
        pair <int, int> p;
        p.first = u.x;
        p.second = u.y;
        if(mp[p]==1)  ways = 1;
        for(int i=0; i<4; i++)
        {
            v.x = u.x + dirx[i];
            v.y = u.y + diry[i];
            if(v.x<n && v.x>=0 && v.y<m && v.y>=0 && arr[v.x][v.y]!='#')    ways = ways + 1;
        }
        v.prob = u.prob/ways;
        for(int i=0; i<4; i++)
        {
            v.x = u.x + dirx[i];
            v.y = u.y + diry[i];
            if(v.x<n && v.x>=0 && v.y<m && v.y>=0 && arr[v.x][v.y]!='#' && arr[v.x][v.y]!='*' && !vis[v.x][v.y])
            {
                vis[v.x][v.y]=1;
                q.push(v);
            }
        }
        if(mp[p]==0)    continue;
        for(int i=0; i<k; i++)
        {
            if(tunnel[i][0]==u.x && tunnel[i][1]==u.y)
            {
                v.x = tunnel[i][2];
                v.y = tunnel[i][3];
                if(vis[v.x][v.y])   continue;
                q.push(v);
                vis[v.x][v.y]=1;
                mp[p]=0;
                p.first=v.x;
                p.second=v.y;
                mp[p]=0;
                break;
            }
            else if(tunnel[i][2]==u.x && tunnel[i][3]==u.y)
            {
                v.x = tunnel[i][0];
                v.y = tunnel[i][1];
                if(vis[v.x][v.y])   continue;
                q.push(v);
                vis[v.x][v.y]=1;
                mp[p]=0;
                p.first=v.x;
                p.second=v.y;
                mp[p]=0;
                break;
            }
        }
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int k, x, y;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='A')
            {
                x=i;
                y=j;
            }
        }
        getchar();
    }
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin>>tunnel[i][j];
            tunnel[i][j]--;
        }
        pair <int, int> p;
        p.first = tunnel[i][0];
        p.second = tunnel[i][1];
        mp[p]=1;
        p.first = tunnel[i][2];
        p.second = tunnel[i][3];
        mp[p]=1;
    }
    cout<<bfs(x,y,k);

    return 0;
}
/*
4 6 1
###*OO
O#OAOO
%##*OO
O#OOOO
2 3 2 1
*/
