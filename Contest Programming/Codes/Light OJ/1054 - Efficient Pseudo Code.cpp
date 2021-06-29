#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool flag[47000];
vector <int> primes;
int BigMod(long long B, long long P, long long M)
{
    long long R=1;
    while(P>0)
    {
        if(P%2==1)  R=(R*B)%M;
        P/=2;
        B=(B*B)%M;
    }
    return R;
}
void seive()
{
    int l = sqrt(INT_MAX)+1;
    for(int i=0; i<l; i++)  flag[i]=1;
    int val = sqrt(l)+1;
    for(int i=2; i<val; i++)
    {
        if(flag[i])
        {
            for(int j=i; j*i<=l; j++)
                flag[i*j]=0;
        }
    }
    for(int i=2; i<=l; i++)
    {
        if(flag[i])
        {
            primes.push_back(i);
            //if(i<100)   printf("%d\n", i);
        }
    }
}
int main()
{
    seive();
    //printf("%d\n", primes.size());
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        vector <long long> factors;
        vector <long long> factorcnt;
        int s = primes.size();
        for(int i=0; i<s; i++)
        {
            if(n%primes[i]==0)
            {
                factors.push_back(primes[i]);
                int cnt=0;
                while(n%primes[i]==0)
                {
                    cnt++;
                    n/=primes[i];
                    //printf("%d %d %d\n", n, primes[i], cnt);
                }
                factorcnt.push_back(cnt*m);
            }
        }
        if(n!=1)
        {
            factors.push_back(n);
            factorcnt.push_back(1LL*m);
        }
        s = factors.size();
        long long ans=1;
        for(int i=0; i<s; i++)
        {
            //printf("%lld %lld\n", factors[i], factorcnt[i]);
            long long tmp = BigMod(factors[i], factorcnt[i]+1, mod)-1;
            //cout<<tmp<<endl;
            if(tmp<0)   tmp=1;
            else tmp = (tmp*BigMod(factors[i]-1, mod-2, mod))%mod;
            ans = (ans * tmp) % mod;
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
