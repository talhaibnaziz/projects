#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t<cases)
    {
        long long ans=0, n, i, cnt, j;
        scanf("%lld", &n);
        for(i=4, j=0; i<=n; i=i*2, j++)
        {
            cnt=1<<j;
            ans+=(n/i)*cnt;
            if(n%i>0 && ((n%i)+cnt)>=i) ans+=((n+cnt)%i)+1;
            //cout<<i<<' '<<j<<' '<<cnt<<' '<<ans<<endl;
        }
        cnt=1<<j;
        if((n+cnt)>=i)  ans+=((n+cnt)%i)+1;
        printf("Case %d: %lld\n", ++t, ans);
    }

    return 0;
}
