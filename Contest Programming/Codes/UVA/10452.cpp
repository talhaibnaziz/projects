#include <bits/stdc++.h>
using namespace std;

int m, n;
char ar[10][10];
int dirx[4]={0, -1, 0};
int diry[4]={-1, 0, 1};
bool flag;

vector <string> ans;
char letters[10]="@IEHOVA\0";

void dfs(int x, int y, int ser)
{
    //cout<<x<<' '<<y<<endl;
    if(x<0 || y<0 || x==m || y==n)  return;
    if(flag)    return;
    if(ar[x][y]=='#' && ser==7)
    {
        flag=1;
        //cout<<x<<' '<<y<<endl;
        return;
    }
    if(ser==7)  return;
    if(letters[ser]!=ar[x][y])  return;
    for(int i=0; i<3; i++)
    {
        if(i==0)    ans.push_back("left");
        else if(i==1)   ans.push_back("forth");
        else    ans.push_back("right");
        dfs(x+dirx[i], y+diry[i], ser+1);
        if(flag)    break;
        ans.pop_back();
    }
}

int main()
{
    //freopen("out.txt", "w", stdout);
    //freopen("in.txt", "r", stdin);
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        scanf("%d %d", &m, &n);
        getchar();
        flag=0;
        for(int i=0; i<m; i++)  scanf("%s", &ar[i]);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(ar[i][j]=='@')
                {
                    dfs(i, j, 0);
                    break;
                }
            }
            if(flag)    break;
        }
        for(int i=0; i<ans.size()-1; i++) cout<<ans[i]<<' ';
        cout<<ans[ans.size()-1]<<"\n";
        ans.clear();
    }

    return 0;
}
