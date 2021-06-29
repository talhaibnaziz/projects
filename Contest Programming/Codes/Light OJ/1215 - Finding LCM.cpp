#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b)
{
    if(a%b==0)  return b;
    if(b%a==0)  return a;
    if(a>b) return GCD(b, a%b);
    else return GCD(a, b%a);
}
bool flag[1000005];
long long primes[79000];
long long factorcnt[79000];
long long seive()
{
    long long i, j, total=0, val;
    for(i=2; i<=1000000; i++)   flag[i]=1;

    val = 1001;

    for(i=2; i<val; i++)
        if(flag[i])
            for(j=i; i*j<=1000000; j++)
                flag[i*j]=0;

    for(i=2; i<=1000000; i++)
        if(flag[i])
            primes[total++]=i;

    return total;
}
int main()
{
    long long primecnt = seive();
    //printf("%lld\n", primecnt);
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long a, b, l;
        scanf("%lld %lld %lld", &a, &b, &l);
        long long gcd = GCD(a, b);
        long long lcm = (a/gcd)*b;
        if(l%lcm==0)
        {
            memset(factorcnt, 0, sizeof factorcnt);
            long long ans=1, req=l/lcm;
            for(long long i=0; i<primecnt; i++)
            {
                if(a==1 && b==1 && req==1)  break;
                while(a%primes[i]==0)
                {
                    factorcnt[i]++;
                    a/=primes[i];
                }
                //cout<<primes[i]<<' '<<factorcnt[i]<<endl;
                long long cnt=0;
                while(b%primes[i]==0)
                {
                    cnt++;
                    b/=primes[i];
                }
                factorcnt[i]=max(factorcnt[i], cnt);
                //cout<<primes[i]<<' '<<factorcnt[i]<<endl;
                //cout<<req<<endl;
                cnt = 0;
                while(req%primes[i]==0)
                {
                    cnt++;
                    req/=primes[i];
                }
                //cout<<primes[i]<<' '<<cnt<<endl;
                if(cnt>0)    for(long long j=0; j<(cnt+factorcnt[i]); j++)    ans*=primes[i];
                //cout<<ans<<endl;
            }
            printf("Case %d: %lld\n", t, ans*req);
        }
        else    printf("Case %d: impossible\n", t);
    }

    return 0;
}
