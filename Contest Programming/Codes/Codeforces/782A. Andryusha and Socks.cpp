#include <bits/stdc++.h>
using namespace std;

bool mp[1000005];
int main()
{
    int n, sock, ans=0, table=0;
    memset(mp, 0, sizeof mp);
    scanf("%d", &n);
    for(int i=0; i<2*n; i++)
    {
        scanf("%d", &sock);
        if(mp[sock]==0)
        {
            mp[sock]=1;
            table++;
        }
        else
        {
            mp[sock]=0;
            table--;
        }
        ans=max(ans, table);
    }
    printf("%d", ans);

    return 0;
}
