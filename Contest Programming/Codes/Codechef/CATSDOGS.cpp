#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long c, d, l;
        scanf("%lld %lld %lld", &c, &d, &l);
        long long maxim, minim;
        maxim = (c+d)*4;
        minim = d*4;
        if(c>2*d)   minim += (c-2*d)*4;
        if(minim<=l && l<=maxim && l%4==0)  printf("yes\n");
        else    printf("no\n");
    }

    return 0;
}
