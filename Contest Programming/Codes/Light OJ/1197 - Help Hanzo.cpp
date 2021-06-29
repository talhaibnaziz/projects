#include <bits/stdc++.h>
using namespace std;

bool flag[47000];
int primes[47000];
bool ans[100010];

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
    //printf("%d\n", total);
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        memset(ans, 1, sizeof ans);
        int a, b;
        scanf("%d %d", &a, &b);
        int sq=sqrt(b)+1;
        if(a==1 && b>1) a=2;
        for(int i=0; primes[i]<sq; i++)
        {
            long long j=a/primes[i];
            if(a%primes[i]!=0)  j++;
            if(j==1)    j++;
            for( ; ((long long)primes[i]*j)<=(long long)b; j++)
            {
                ans[primes[i]*j-a]=0;
                //cout<<primes[i]<<' '<<j<<' '<<primes[i]*j-a<<' '<<b-primes[i]*j<<endl;
            }
        }
        int cnt=0;
        for(int i=0; i<=(b-a); i++)
        {
            if(ans[i])
            {
                cnt++;
                //cout<<i+a<<endl;
            }
        }
        if(a==1 && b==1)    cnt=0;
        printf("Case %d: %d\n", t, cnt);
    }

    return 0;
}
