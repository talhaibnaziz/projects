#include <bits/stdc++.h>
using namespace std;

unsigned long long F(unsigned long long x)
{
    if(x==1) return 1;
    unsigned long long t=F(x/2);
    if(x%2==0)  return t*t+1;
    return t*F(x/2+1)+2;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases, t=0;
    scanf("%d", &cases);
    while(t<cases)
    {
        unsigned long long n;
        scanf("%llu", &n);
        printf("Case %d: %llu\n", ++t, F(n));
    }

    return 0;
}
