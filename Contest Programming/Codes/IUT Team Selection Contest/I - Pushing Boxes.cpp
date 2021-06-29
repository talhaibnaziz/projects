#include <bits/stdc++.h>
using namespace std;

int r, c;
int bx, by, mx, my;
string grid[24];
bool vis[25][25][25][25];

int dirx[5] = {0,0,1,-1};
int diry[5] = {1,-1,0,0};

struct node
{
    int x;
    int y;
    int boxx;
    int boxy;
    string path;
};

string bfs(node u)
{
    queue <node> q;
    node v;
    q.push(u);
    vis[u.x][u.y][u.boxx][u.boxy]=1;
    while(!q.empty())
    {
        u = q.front();
        cout<<u.x<<' '<<u.y<<' '<<u.boxx<<' '<<u.boxy<<endl;
        q.pop();
        for(int i=0; i<4; i++)
        {
            v.x = u.x + dirx[i];
            v.y = u.y + diry[i];
            if(v.x==u.boxx && v.y==u.boxy)
            {
                v.boxx = u.boxx + dirx[i];
                v.boxy = u.boxy + diry[i];
                v.path = u.path;
                if(i==0)     v.path.push_back('e');
                if(i==1)     v.path.push_back('w');
                if(i==2)     v.path.push_back('s');
                if(i==3)     v.path.push_back('n');
            }
            else
            {
                v.boxx = u.boxx;
                v.boxy = u.boxy;
                v.path = u.path;
                if(i==0)     v.path.push_back('E');
                if(i==1)     v.path.push_back('W');
                if(i==2)     v.path.push_back('S');
                if(i==3)     v.path.push_back('N');
            }
            if(v.x>=0 && v.x<r && v.y>=0 && v.y<c && v.boxx>=0 && v.boxx<=r && v.boxy>=0 && v.boxy<=c && !vis[v.x][v.y][v.boxx][v.boxy] && grid[v.x][v.y]!='#' && grid[v.boxx][v.boxy]!='#')
            {
                vis[v.x][v.y][v.boxx][v.boxy]=1;
                q.push(v);
                if(grid[v.boxx][v.boxy]=='T') return v.path;
            }
        }
    }
    v.path = "";
    return v.path;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=0;
    while(1)
    {
        t++;
        cin>>r>>c;
        if(r==0 && c==0)    break;
        for(int i=0; i<r; i++)  cin>>grid[i];
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]=='S')
                {
                    mx = i;
                    my = j;
                }
                else if(grid[i][j]=='B')
                {
                    bx = i;
                    by = j;
                }
            }
        }
        node u;
        u.x = mx; u.y = my;
        u.boxx = bx; u.boxy = by;
        memset(vis, 0, sizeof vis);
        string ans = bfs(u);
        cout<<"Maze #"<<t<<'\n';
        if(ans.size()==0)   cout<<"Impossible.\n";
        else    cout<<ans<<'\n';
    }

    return 0;
}
