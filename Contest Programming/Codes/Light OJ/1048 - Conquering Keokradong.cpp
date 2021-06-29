#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    int arr[1010];
    while(t++<cases)
    {
        int n, k;
        int min_val=100000000;
        scanf("%d %d", &n, &k);
        int tot = 0;
        for(int i = 0; i<=n; i++)
        {
            scanf("%d", &arr[i]);
            tot += arr[i];
        }
        int lo = tot/(k+1);
        int hi = tot;
        int mid;
        while(hi>=lo)
        {
            mid = (lo + hi)/2;
            //printf("%d %d %d\n", hi, mid, lo);
            int sum = 0, cnt = 0, max_sum = 0;
            for(int i=0; i<=n; i++)
            {
                sum+=arr[i];
                if(sum>mid)
                {
                    max_sum = max(sum-arr[i], max_sum);
                    sum = arr[i];
                    cnt++;
                }
            }
            max_sum = max(sum, max_sum);
            //cout<<cnt<<' '<<max_sum<<endl;
            if(cnt>k)
            {
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
                min_val = min( max_sum, min_val );
            }
        }
        int sum = 0;
        int steps = 0;
        int flag = 0;
        printf("Case %d: %d\n", t, min_val);
        for(int i=0; i<=n; i++)
        {
            sum+=arr[i];
            if((k-steps)==(n+1-i))    flag = i;
            if(flag!=0) break;
            if(sum>min_val)
            {
                printf("%d\n", sum-arr[i]);
                steps++;
                sum = arr[i];
            }
        }
        if(flag==0) printf("%d\n", sum);
        else
        {
            printf("%d\n", sum-arr[flag]);
            for(int i=flag; i<=n; i++)  printf("%d\n", arr[i]);
        }
    }

    return 0;
}
