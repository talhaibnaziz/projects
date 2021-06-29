#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n>1) printf("%d %d %d", n, n+1, n*(n+1));
    else    printf("-1");

    return 0;
}
