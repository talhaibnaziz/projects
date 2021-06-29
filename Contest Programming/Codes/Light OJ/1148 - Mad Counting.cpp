#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    int arr[55];
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++)  scanf("%d", &arr[i]);
        sort(arr, arr+n);
        int cnt, tmp=0, ans=0;
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                tmp=1;
                cnt=arr[i]+1;
            }
            else if(arr[i]==arr[i-1])
            {
                tmp++;
                if(tmp>cnt)
                {
                    ans+=cnt;
                    tmp = 1;
                }
            }
            else
            {
                ans+=cnt;
                cnt = arr[i]+1;
                tmp=1;
            }
            //cout<<i<<' '<<cnt<<' '<<tmp<<' '<<ans<<endl;
        }
        ans+=cnt;
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
