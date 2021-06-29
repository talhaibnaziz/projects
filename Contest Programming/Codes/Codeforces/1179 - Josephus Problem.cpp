#include <bits/stdc++.h>
using namespace std;

long long josephus(long long n, long long k)
{
    //cout<<n<<' '<<k<<endl;
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}

int main()
{
    int cases, t=0; scanf("%d", &cases);
    while(t++<cases)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        printf("Case %d: %lld\n", t, josephus(n, k));
    }

    return 0;
}
