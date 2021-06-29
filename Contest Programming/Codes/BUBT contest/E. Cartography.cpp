#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long m, k;
        scanf("%lld %lld", &m, &k);
        long long ans=k*(k-1);
        for(int i=1; i<m; i++)
        {
            ans=ans*((k-2)*(k-2)+(k-1));
            ans%=1000000007;
        }
        if(k==2)    ans=2;
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
