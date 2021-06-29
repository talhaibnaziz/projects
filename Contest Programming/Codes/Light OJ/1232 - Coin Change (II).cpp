#include <bits/stdc++.h>
using namespace std;
int n, k, ar[110];
long long dp[10010];

int main()
{
    int t=0, cases;
    cin>>cases;
    while(t<cases)
    {
        cin>>n>>k;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &ar[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=k; j++)
            {
                if(ar[i]<=j)    dp[j]+=dp[j-ar[i]];
                dp[j]%=100000007;
            }
        }
        printf("Case %d: %lld\n", ++t, dp[k]);
    }

    return 0;
}
