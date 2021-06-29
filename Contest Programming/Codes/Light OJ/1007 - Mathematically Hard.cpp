#include <bits/stdc++.h>
using namespace std;

unsigned long long num[5000010];
bool prime[5000010];
vector <int> primes;
unsigned long long GCD(unsigned long long a, unsigned long long b)
{
    if(a%b==0)  return b;
    if(b%a==0)  return a;
    if(a>b) return GCD(b, a%b);
    else return GCD(a, b%a);
}
void myseive()
{
    int val=sqrt(5000000)+1;
    //cout<<val<<endl;
    for(int i=2; i<5000001; i++)
    {
        prime[i]=1;
        num[i]=(unsigned long long)i;
    }
    prime[1]=0;
    //cout<<"000"<<endl;
    for(int i=2; i<val; i++)
    {
        if(prime[i])
        {
            //cout<<i<<endl;
            for(int j=i; i*j<5000001; j++)
            {
                prime[i*j]=0;
            }
        }
    }
    for(int i=2; i<5000001; i++)    if(prime[i])    primes.push_back(i);
}
void phi()
{
    int val=sqrt(5000000)+1;
    int s=primes.size();
    //cout<<s<<' '<<primes[s-1]<<endl;
    num[2]--;
    num[3]--;
    for(int i=4; i<5000001; i++)
    {
        if(prime[i])
        {
            num[i]--;
            continue;
        }
        int d=i;
        unsigned long long den=1;
        for(int j=0; j<s; j++)
        {
            int p=primes[j];
            if(d%p==0)
            {
                num[i]*=(unsigned long long)(p-1);
                den*=(unsigned long long)p;
                while(d%p==0)   d/=p;
                unsigned long long g=GCD(num[i], den);
                num[i]/=g;
                den/=g;
                if(d==1)    break;
                if(prime[d])
                {
                    num[i]*=(unsigned long long)(d-1);
                    den*=(unsigned long long)d;
                    g=GCD(num[i], den);
                    num[i]/=g;
                    den/=g;
                    //if(i==6)    cout<<num[i]<<'/'<<den[i]<<endl;
                    break;
                }
            }
        }
    }
}
int main()
{
    int cases, t=0;
    myseive();
    //cout<<"000"<<endl;
    phi();
    num[1]=0;
    for(int i=2; i<=5000000; i++)
    {
        num[i]*=num[i];
        //if(i<100)   cout<<i<<' '<<ans[i]<<endl;
        num[i]+=num[i-1];
    }
    scanf("%d", &cases);
    while(t++<cases)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", t, num[b]-num[a-1]);
    }

    return 0;
}
