#include <bits/stdc++.h>
using namespace std;
int n, w, k;
int range[110], y[110];
int dp[110][110];

int rec(int mov, int idx)
{
    if(dp[mov][idx]!=-1)    return  dp[mov][idx];
    if(mov==k)  return dp[mov][idx]=0;
    if(idx==n)  return dp[mov][idx]=0;
    //cout<<mov<<' '<<idx<<endl;
    int lim=y[idx]+w, sum=0, i;
    for(i=idx; i<n && y[i]<=lim; i++)
    {
        sum++;
    }
    //cout<<mov<<' '<<idx<<' '<<sum<<' '<<endl;
    int a=rec(mov+1, i) + sum;
    int b=rec(mov, idx+1);

    return dp[mov][idx]=max(a, b);
}
int main()
{
    int t=0, cases;
    int inx[110], iny[110];
    scanf("%d", &cases);
    while(t<cases)
    {
        scanf("%d %d %d", &n, &w, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &inx[i], &iny[i]);
            y[i]=iny[i];
        }
        sort(y, y+n);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", ++t, rec(0, 0));
    }

    return 0;
}
