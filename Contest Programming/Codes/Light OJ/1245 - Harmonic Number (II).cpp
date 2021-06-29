#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long n;
        scanf("%lld", &n);
        long long val = sqrt(n)+1;
        long long prev = 0, ans = 0;
        for(long long i=1; i<val; i++)
        {
            long long dividend = n/i;
            ans+=dividend;
            if(prev==0) prev = dividend;
            else
            {
                ans+=(prev-dividend)*(i-1);
                prev = dividend;
            }
            //cout<<i<<' '<<prev<<' '<<dividend<<' '<<ans<<endl;
        }
        ans+=(prev-(val-1))*(val-1);
        //cout<<val-1<<' '<<prev<<' '<<val-1<<' '<<ans<<endl;
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
