#include <bits/stdc++.h>
using namespace std;
long long csod(long long n) {
  long long ans = 0;
  for (long long i = 2; i * i <= n; ++i) {
    long long j = n / i;
    ans += (i + j) * (j - i + 1) / 2;
    ans += i * (j - i);
  }
  return ans;
}
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long n;
        scanf("%lld", &n);

        printf("Case %d: %lld\n", t, csod(n));
    }

    return 0;
}
