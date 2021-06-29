#include <bits/stdc++.h>
using namespace std;

int grid[105][105][11]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, c;
    cin>>n>>q>>c;
    for(int i=0; i<n; i++)
    {
        int x, y, s;
        cin>>x>>y>>s;
        grid[x][y][s]++;
    }
    for(int i=1; i<101; i++)
    {
        for(int j=1; j<101; j++)
        {
            for(int k=0; k<11; k++)
            {
                grid[i][j][k] += grid[i-1][j][k]+grid[i][j-1][k]-grid[i-1][j-1][k];
            }
        }
    }
    for(int i=0; i<q; i++)
    {
        int t, xl, yl, xr, yr;
        cin>>t>>xl>>yl>>xr>>yr;
        int ans[11], sum=0;
        for(int j=0; j<11; j++)
        {
            ans[j] = grid[xr][yr][j];
            ans[j] -= grid[xl-1][yr][j]+grid[xr][yl-1][j]-grid[xl-1][yl-1][j];
            //cout<<ans[j]<<' ';
            ans[j] = ans[j]*((j+t)%(c+1));
            sum += ans[j];
        }
        cout<<sum<<"\n";
    }

    return 0;
}
