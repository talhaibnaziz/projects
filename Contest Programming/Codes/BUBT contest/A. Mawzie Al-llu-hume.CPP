#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long n;
        int k;
        scanf("%d %lld", &k, &n);
        printf("Case %d:\n", t);
        if(k==0)
        {
            printf("%lld\n", n/3);
            n=n*2/3;
            printf("%lld\n%lld\n", 2*n/3, n/3);
        }
        else
        {
            n=n*3;
            n=n*3/2;
            long long ans=n;
            printf("%lld\n", n/3);
            n=n*2/3;
            printf("%lld\n%lld\n", 2*n/3, ans);
        }
    }

    return 0;
}
