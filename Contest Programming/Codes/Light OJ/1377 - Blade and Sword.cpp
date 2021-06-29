#include <bits/stdc++.h>
using namespace std;
char ar[210][210];
int dis[2][210][210];
int dirx[]={1, -1, 0, 0};
int diry[]={0, 0, 1, -1};
int m, n, star;
int playerx, playery, desx, desy;
struct pos
{
    int x, y;
};
int findstar(int rec, int x, int y)
{
    pos p; int ret=9999999;
    p.x=x; p.y=y;
    dis[rec][x][y]=0;
    queue <pos> q;
    q.push(p);
    while(!q.empty())
    {
        pos u=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            p.x=u.x+dirx[i];
            p.y=u.y+diry[i];
            if(p.x<0 || p.x==m || p.y<0 || p.y==n)  continue;
            if(ar[p.x][p.y]=='#')   continue;
            if(dis[rec][p.x][p.y]==-1)
            {
                q.push(p);
                dis[rec][p.x][p.y]=dis[rec][u.x][u.y]+1;
                if(ar[p.x][p.y]=='*' && rec==0)
                {
                    for(int loop1=0; loop1<m; loop1++)
                    {
                        for(int loop2=0; loop2<n; loop2++)
                        {
                            dis[1][loop1][loop2]=-1;
                        }
                    }
                    dis[1][p.x][p.y]=0;
                    ret=min(ret,dis[rec][p.x][p.y]+findstar(rec+1, desx, desy)+1);
                }
                else if(ar[p.x][p.y]=='*')  return  dis[rec][p.x][p.y];
            }
        }
    }

    return ret;
}
int finddes(int x, int y)
{
    pos p;
    p.x=x; p.y=y;
    dis[0][x][y]=0;
    queue <pos> q;
    q.push(p);
    while(!q.empty())
    {
        pos u=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            p.x=u.x+dirx[i];
            p.y=u.y+diry[i];
            if(p.x<0 || p.x==m || p.y<0 || p.y==n)  continue;
            if(ar[p.x][p.y]=='#')   continue;
            if(ar[p.x][p.y]=='*' && star<2)   continue;
            if(ar[p.x][p.y]=='D')   return dis[0][u.x][u.y]+1;
            if(dis[0][p.x][p.y]==-1)
            {
                q.push(p);
                dis[0][p.x][p.y]=dis[0][u.x][u.y]+1;
                if(ar[p.x][p.y]=='*')   dis[0][p.x][p.y]+=2;
            }
        }
    }

    return 9999999;
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        star=0;
        scanf("%d %d", &m, &n);
        getchar();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%c", &ar[i][j]);
                if(ar[i][j]=='P')
                {
                    playerx=i;
                    playery=j;
                }
                else if(ar[i][j]=='D')
                {
                    desx=i;
                    desy=j;
                }
                else if(ar[i][j]=='*')   star++;
            }
            getchar();
        }
        memset(dis, -1, sizeof dis);
        int dis1, dis2;
        dis1=finddes(playerx, playery);
        memset(dis, -1, sizeof dis);
        dis2=findstar(0, playerx, playery);
        //cout<<dis1<<' '<<dis2<<endl;
        int ans=min(dis1, dis2);
        if(ans>999999)  printf("Case %d: impossible\n", t);
        else printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
