#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        long long sum=0, last=0, car;
        for(int i=0; i<n; i++)
        {
            scanf("%lld", &car);
            sum+=car;
            if(i==(n-1))    last=car;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%lld", &car);
            sum+=car;
            if(i==(m-1))    last=max(last,car);
        }
        printf("Case %d: %lld\n", t, sum-last);
    }

    return 0;
}
