#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, v, u;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &u, &v);
        long long n = u+v;
        n = n*(n+1)/2 + u +1;
        printf("%lld\n", n);
    }

    return 0;
}
