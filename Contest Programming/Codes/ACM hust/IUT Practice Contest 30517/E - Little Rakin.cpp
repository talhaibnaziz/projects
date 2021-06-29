#include <bits/stdc++.h>
using namespace std;

bool prime[1005];
vector <int> primes;

void seive()
{
    memset(prime, 1, sizeof prime);
    prime[0]=0; prime[1]=1;
    int val = sqrt(1000)+1;
    for(int i=2; i<val; i++)
    {
        if(!prime[i])   continue;
        //cout<<i<<endl;
        for(int j=i; j*i<1001; j++)
        {
            prime[j*i]=0;
        }
    }
    for(int i=2; i<=1000; i++)  if(prime[i])    primes.push_back(i);
}
int main()
{
    seive();
    int t, n, a, b;
    long long f[45][170];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &a, &b);
        int idx = 0;
        memset(f, 0, sizeof f);
        while(a!=1)
        {
            if(a%primes[idx]==0)
            {
                a/=primes[idx];
                f[0][idx]++;
            }
            else    idx++;
        }
        idx = 0;
        while(b!=1)
        {
            if(b%primes[idx]==0)
            {
                b/=primes[idx];
                f[1][idx]++;
            }
            else    idx++;
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<168; j++)    f[i][j]=f[i-1][j]+f[i-2][j];
        }
        for(int i=0; i<168; i++)    if(f[n][i]!=0)  printf("%d %d\n", primes[i], f[n][i]);
        printf("\n");
    }

    return 0;
}
