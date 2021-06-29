#include <bits/stdc++.h>
using namespace std;

long long maxSubArraySum(long long a[], long long sze)
{
    long long max_so_far = -99999999999999999, max_ending_here = 0;

    for (long long i = 0; i < sze; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
long long arr[100005];
long long difa[100005], difb[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d", &arr[i]);
    }
    for(int i=0; i<(n-1); i++)
    {
        difa[i]=arr[i]-arr[i+1];
        if(difa[i]<0)   difa[i]*=-1;
        if(i%2) difa[i]*=-1;
        difb[i]=difa[i]*-1;
    }
    difb[0]=0;
    long long ans = maxSubArraySum(difa, n-1);
    ans = max(ans, maxSubArraySum(difb, n-1));
    printf("%I64d", ans);

    return 0;
}
