#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k2, k3, k5, k6;
    scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
    int ans = 0;
    ans+=min(k2, min(k5, k6))*256;
    k2-=min(k2, min(k5, k6));
    ans+=min(k2, k3)*32;
    printf("%d", ans);
    return 0;
}
