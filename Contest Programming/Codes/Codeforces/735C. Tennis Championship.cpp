#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    long long fib[1000];
    fib[0]=1; fib[1]=1;
    int cnt=0;
    for(int i=2; ; i++)
    {
        cnt++;
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i]>n)   break;
    }
    printf("%d", cnt-1);

    return 0;
}
//576460752303423488
