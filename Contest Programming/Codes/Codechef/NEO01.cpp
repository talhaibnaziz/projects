#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main()
{
    int t;
    scanf("%d", &t);
    int n;
    long long total, cnt, negcnt;
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)  scanf("%lld", &a[i]);
        total = 0; cnt = 0;
        negcnt = 0;
        sort(a, a+n);
        for(int i=n-1; i>-1; i--)
        {
            if(a[i]>=0)
            {
                total += a[i];
                cnt++;
            }
            else
            {
                if(((total+a[i])*(cnt+1))>=(total*cnt))
                {
                    total += a[i];
                    cnt++;
                }
                else    negcnt += a[i];
            }
        }
        printf("%lld\n", (total*cnt)+negcnt);
    }

    return 0;
}
