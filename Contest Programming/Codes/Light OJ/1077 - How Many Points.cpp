#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b)
{
    if(a%b==0)  return b;
    if(b%a==0)  return a;
    if(a>b) return GCD(b, a%b);
    else return GCD(a, b%a);
}
int main()
{
    long long cases, t=0; scanf("%lld", &cases);
    while(t++<cases)
    {
        long long ax, ay, bx, by;
        scanf("%lld %lld %lld %lld", &ax, &ay, &bx, &by);
        long long x, y;
        if(ax>bx)   x=ax-bx;
        else x=bx-ax;
        if(ay>by)   y=ay-by;
        else y=by-ay;
        long long ans;
        if(x==0 && y==0)    ans=1;
        else if(x==0)   ans=y+1;
        else if(y==0)   ans=x+1;
        else ans=GCD(x, y)+1;
        printf("Case %lld: %lld\n", t, ans);
    }

    return 0;
}
