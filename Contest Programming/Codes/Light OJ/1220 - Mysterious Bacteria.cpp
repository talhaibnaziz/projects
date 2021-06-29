#include <bits/stdc++.h>
using namespace std;

bool flag[47000];
int primes[47000];
int factors[47000];

int GCD(int a, int b)
{
    if(a%b==0)  return b;
    if(b%a==0)  return a;
    if(a>b) return GCD(b, a%b);
    else return GCD(a, b%a);
}
int seive()
{
    int total=0;
    for(int i=0; i<47000; i++)  flag[i]=1;
    int val = sqrt(47000)+1;
    for(int i=2; i<val; i++)
    {
        if(flag[i])
        {
            for(int j=i; j*i<47000; j++)
                flag[i*j]=0;
        }
    }
    for(int i=2; i<47000; i++)
    {
        if(flag[i])
        {
            primes[total++]=i;
            //if(i<100)   cout<<i<<endl;
        }
    }

    return total;
}

int main()
{
    int total = seive();
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        memset(factors, 0, sizeof factors);
        long long x;
        scanf("%lld", &x);
        //cout<<x<<endl;
        int n = x;
        if(x<0) x/=-1;
        int val = sqrt(x)+1;
        int gcd = 0;
        for(int i=0; primes[i]<val; i++)
        {
            while(x%primes[i]==0)
            {
                factors[i]++;
                x/=primes[i];
            }
            if(factors[i]!=0)
            {
                if(gcd==0)  gcd = factors[i];
                gcd = GCD(gcd, factors[i]);
                //cout<<primes[i]<<' '<<factors[i]<<' '<<gcd<<endl;
            }
        }
        if(x!=1)    gcd=1;
        if(gcd%2==0 && n<0) while(gcd%2==0) gcd/=2;
        printf("Case %d: %d\n", t, gcd);
    }

    return 0;
}
