#include <bits/stdc++.h>
using namespace std;

int m, a, b, r, ans;
int ar[205];

void rec(int player, int team)
{
    if(team==4)
    {
        if(r>=a && r<=b)    ans++;
        return;
    }
    if(player==m)   return;
    if(r>b) return;
    rec(player+1, team);
    r+=ar[player];
    rec(player, team+1);
    r-=ar[player];
}

int main()
{
    freopen("in.txt", "r", stdin);
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        scanf("%d", &m);
        for(int i=0; i<m; i++)  scanf("%d", &ar[i]);
        scanf("%d %d", &a, &b);
        r=0, ans=0;
        rec(0, 0);
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
