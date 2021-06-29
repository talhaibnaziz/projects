#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ar[100][100], sum[100][100];
    memset(sum, 0, sizeof(sum));
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>ar[i][j];
            if(i==0 && j==0)    continue;
            else if(i==0)   sum[i][j]+=sum[i][j-1];
            else if(j=)
        }
    }
}
