#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long a[100005], b[100005], c[100005];
long long asum[100005], csum[100005];
int main()
{
    long long t, p, q, r;
    long long n, ans;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &p, &q, &r);
        ans = 0;
        for(long long i=0; i<p; i++)
        {
            scanf("%lld", &a[i]);
            if(i==0)    asum[i] = a[i];
            else    asum[i] = asum[i-1]+a[i];
        }
        for(long long i=0; i<q; i++)
        {
            scanf("%lld", &b[i]);
        }
        for(long long i=0; i<r; i++)
        {
            scanf("%lld", &c[i]);
            if(i==0)    csum[i] = c[i];
            else    csum[i] = csum[i-1]+c[i];
        }
        sort(a, a+p);
        sort(b, b+q);
        sort(c, c+r);
        long long ii = p - 1, jj = r - 1, x, y, z;
        long long i = q-1;
        while(i>-1 && ii>-1 && jj>-1)
        {
            x = a[ii]%mod; y = b[i]%mod; z = c[jj]%mod;
            if(x>y) ii--;
            else if(z>y) jj--;
            else
            {
                x = asum[ii]%mod; z = csum[jj]%mod;
                ans += (x*z)%mod + ((x*y)%mod)*(jj+1) + ((z*y)%mod)*(ii+1) + ((((ii+1)*(jj+1))%mod)*((y*y)%mod))%mod;
                ans %= mod;
                i--;
            }
            //cout<<ii<<' '<<jj<<endl;
        }
        printf("%lld", ans);
        if(t>0) printf("\n");
    }

    return 0;
}
