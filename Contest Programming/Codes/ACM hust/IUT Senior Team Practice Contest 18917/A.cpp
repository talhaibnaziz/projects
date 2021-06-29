#include <bits/stdc++.h>
using namespace std;
int r, c;
int magrid[505][505];
int ans[505][505];

int dfs(int x, int y, int str)
{
    //cout<<"in: "<<x<<' '<<y<<' '<<str<<endl;
    if(x<1 || x>r || y<1 || y>c)    return 99999999;
    ans =
    int a = dfs(x+1, y, str-magrid[x][y]);
    int b = dfs(x, y+1, str-magrid[x][y]);
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        cin>>r>>c;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                cin>>magrid[i][j];
                ans[i][j]=99999999;
            }
        }
        dfs(1,1,1);
    }

    return 0;
}
