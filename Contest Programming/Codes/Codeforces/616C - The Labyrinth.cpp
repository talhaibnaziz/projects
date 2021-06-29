#include <bits/stdc++.h>
using namespace std;

char ar[1005][1005];
int grid[1005][1005]={};
int mark[1005][1005]={};
int n, m, cnt, fillcnt = 0;

void floodfill(int i, int j)
{
    if(i<0 || i==n || j<0 || j==m)  return;
    if(ar[i][j]!='.')   return;
    ar[i][j]='$';
    cnt++;
    floodfill(i+1, j);
    floodfill(i-1, j);
    floodfill(i, j+1);
    floodfill(i, j-1);
}
void fullfil(int i, int j)
{
    if(i<0 || i==n || j<0 || j==m)  return;
    if(ar[i][j]!='$')   return;
    ar[i][j]='#';

    if(i>0 && ar[i-1][j]=='*' && mark[i-1][j] != fillcnt)
    {
        grid[i-1][j] += cnt;
        mark[i-1][j] = fillcnt;
    }
    if(i<n-1 && ar[i+1][j]=='*' && mark[i+1][j] != fillcnt)
    {
        grid[i+1][j] += cnt;
        mark[i+1][j] = fillcnt;
    }
    if(j>0 && ar[i][j-1]=='*' && mark[i][j-1] != fillcnt)
    {
        grid[i][j-1] += cnt;
        mark[i][j-1] = fillcnt;
    }
    if(j<m-1 && ar[i][j+1]=='*' && mark[i][j+1] != fillcnt)
    {
        grid[i][j+1] += cnt;
        mark[i][j+1] = fillcnt;
    }

    fullfil(i+1, j);
    fullfil(i-1, j);
    fullfil(i, j+1);
    fullfil(i, j-1);
}
int main()
{
    int i, j, k;
    scanf("%d %d", &n, &m);
    getchar();
    for(i=0; i<n; i++)  scanf("%s", &ar[i]);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(ar[i][j]=='.')
            {
                cnt=0; fillcnt++;
                floodfill(i, j);
//                printf("\n%d %d %d\n", i, j, cnt);
//                for(k=0; k<n; k++)  printf("%s\n", ar[k]);
//                printf("\n");
                fullfil(i, j);
//                for(k=0; k<n; k++)
//                {
//                    for(int jj=0; jj<m; jj++)
//                        printf("%d ", grid[k][jj]);
//                    printf("\n");
//                }
//                printf("\n");
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(ar[i][j]=='*')   ar[i][j] = 48 + (++grid[i][j])%10;
            else    ar[i][j] = '.';
        }
    }

    for(i=0; i<n; i++)  printf("%s\n", ar[i]);

    return 0;
}
