#include <bits/stdc++.h>
using namespace std;

bool prime[10000005];
long long primes[10000005];
long long cnt;
pair <long long, long long> arr[100000000];

void seive()
{
    memset(prime, 1, sizeof prime);
    prime[0]=0; prime[1]=0;
    int val = sqrt(10000000)+1; cnt=0;
    for(int i=2; i<val; i++)
    {
        if(!prime[i])   continue;
        for(int j=i; j*i<1000000; j++)
            prime[j*i]=0;
    }
    for(int i=2; i<10000000; i++) if(prime[i])    primes[cnt++]=i;
}

int main()
{
    seive();
    int idx = 0;
    for(long long i=0; i<cnt; i++)
    {
        for(long long j=primes[i]*primes[i]; j<1000000000000LL; j*=primes[i])
        {
            arr[idx].first = j;
            arr[idx].second = primes[i];
            idx++;
        }
    }
    for(int i=0; i<100; i++)    cout<<arr[i].first<<' '<<arr[i].second<<endl;

    return 0;
}
