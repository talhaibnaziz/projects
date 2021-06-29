#include <bits/stdc++.h>
using namespace std;

long long x[1000005];
long long y[1000005];

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        for(long long i=0; i<n; i++)    scanf("%lld", &x[i]);
        for(long long i=0; i<n; i++)    scanf("%lld", &y[i]);
        for(long long i=0; i<n; i++)    x[i] = y[i]-x[i];
        sort(x, x+n);
        int i=n-1;
        long long profit = 0;
        while((i>=0 && x[i]>0) || i>=k)
        {
            profit += x[i];
            i--;
        }
        if(profit>0)    printf("Case %d: %lld\n", t, profit);
        else    printf("Case %d: No Profit\n", t);
    }

    return 0;
}
