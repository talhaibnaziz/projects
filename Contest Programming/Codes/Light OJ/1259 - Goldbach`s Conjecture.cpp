#include <bits/stdc++.h>
using namespace std;

bool prime[10000003];
vector <int> primes;
int lastprime, cnt;
void seive()
{
    cnt=0;
    memset(prime, 1, sizeof prime);
    prime[1]=0; prime[0]=0;
    int val=sqrt(10000000)+1;
    for(int i=2; i<val; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=10000000; j+=i)
            {
                prime[j]=0;
            }
        }
    }
    for(int i=2; i<=10000000; i++)
    {
        if(prime[i])    primes.push_back(i);
    }
}
int FindSol(int n)
{
    int res=0;
    int s=primes.size();
    for(int i=0; i<s; i++)
    {
        if(primes[i]>n/2)   break;
        if(prime[n-primes[i]])  res++;
    }

    return res;
}
int main()
{
    seive();
    int cases, t=0;
    //cout<<cnt<<endl;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", t, FindSol(n));
    }

    return 0;
}
