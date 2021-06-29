#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(a%b==0)  return b;
    if(b%a==0)  return a;
    if(a>b) return GCD(b, a%b);
    else return GCD(a, b%a);
}

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t<cases)
    {
        int n, c=0, lp, rp=0, x;
        scanf("%d", &n);
        lp=n;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x);
            if(x<0) rp++;
            c+=abs(x);
        }
        printf("Case %d: ", ++t);
        if(lp==rp)  printf("inf\n");
        else
        {
            int gcd=GCD(c, lp-rp);
            printf("%d/%d\n", c/gcd, (lp-rp)/gcd);
        }
    }

    return 0;
}
