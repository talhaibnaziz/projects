#include <stdio.h>
#include <math.h>

int main()
{
    //printf("%lf", log10(16)/log10(2));
    int n;
    double s, ans;
    int rad;
    scanf("%d", &n);
    printf("%04x\n", n);
    printf("%lf\n", s=ceil(log2(n)/log2(16)));
    ans = pow(16, s)-(double)n;
    rad=(int)ans;
    printf("%04x\n", rad);
    printf("%04x", rad-1);


    return 0;
}
