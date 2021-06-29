#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long k;
    cin>>n>>k;
    k--;
    if(k%2==0)  printf("1");
    else
    {
        long long lft = 1, rt = 1;
        int ans = n;
        for(int i=0; i<n; i++)  rt = 2*rt;
        rt-=3;
        while(1)
        {
            long long mid = (rt + lft)/2;
            //if(mid<0)   break;
            //cout<<lft<<' '<<mid<<' '<<rt<<' '<<ans<<endl;
            if(mid==k)  break;
            else if(mid>k)
            {
                rt = mid - 2;
                ans--;
            }
            else
            {
                lft = mid +2;
                ans--;
            }

        }
        printf("%d", ans);
    }

    return 0;
}
