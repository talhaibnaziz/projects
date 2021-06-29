#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    bool row[100010], col[100010];
    cin>>n>>m;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    long long r=n, c=n;
    long long ans[100010];
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        if(!row[x])
        {
            row[x]=1;
            r--;
        }
        if(!col[y])
        {
            col[y]=1;
            c--;
        }
        ans[i]=r*c;
    }
    for(int i=0; i<m; i++)
    {
        if(i==0)    cout<<ans[i];
        else cout<<' '<<ans[i];
    }

    return 0;
}
