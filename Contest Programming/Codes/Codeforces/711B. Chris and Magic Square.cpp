#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long ar[505][505], rows[510]={0}, col[510]={0}, diag1=0, diag2=0;
    cin>>n;
    int x, y, i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>ar[i][j];
            if(ar[i][j]==0)
            {
                x=i;
                y=j;
            }
            rows[i]+=ar[i][j];
            col[j]+=ar[i][j];
        }
    }
    if(x>0) ar[x][y]=rows[0]-rows[x];
    else if(x==0 && n>1)    ar[x][y]=rows[1]-rows[0];
    else ar[x][y]=1;
    rows[x]+=ar[x][y];
    col[y]+=ar[x][y];
    long long comp=rows[0];
    bool flag=1;
    for(i=0; i<n; i++)
    {
        if(rows[i]!=comp || col[i]!=comp)
        {
            flag=0;
            break;
        }
    }
    for(i=0; i<n; i++)  diag1+=ar[i][i];
    for(i=0; i<n; i++)  diag2+=ar[i][n-i-1];
    if(diag1!=comp || diag2!=comp)   flag=0;
    if(ar[x][y]<1)  flag=0;
    //cout<<ar[x][y]<<' '<<diag1<<' '<<diag2<<endl;
    if(flag)    cout<<ar[x][y];
    else printf("-1");

    return 0;
}
