#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0, c[1010];
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m, lo=0, hi=0;
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &c[i]);
            lo = max(lo,c[i]);
            hi += c[i];
        }
        int mid, cnt, sum, ans=hi;
        while(hi>=lo)
        {
            mid = (lo+hi)/2;
            cnt = 0; sum = 0;
            for(int i=0; i<n; i++)
            {
                sum += c[i];
                if(sum>mid)
                {
                    cnt++;
                    sum = c[i];
                }
            }
            cnt++;
            if(cnt>m)   lo = mid+1;
            else
            {
                hi = mid-1;
                ans = min(ans, mid);
            }
        }

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
