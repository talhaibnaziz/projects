#include <bits/stdc++.h>
using namespace std;

long long BigMod(long long B, long long P, long long M)
{
    long long R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

long long Inverse_Modulo(long long a, long long m)
{
    return BigMod(a, m-2, m);
}
long long num[1000003], den[1000003];
int main()
{
    num[0]=1; den[0]=1;
    num[1]=1; den[1]=1;
    for(long long i=2; i<=1000000; i++)
    {
        num[i]=i*num[i-1];
        num[i]%=1000003;
        den[i]=den[i-1]*Inverse_Modulo(i, 1000003);
        den[i]%=1000003;
    }
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        long long ans=(num[n]*den[k]*den[n-k])%1000003;
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}
