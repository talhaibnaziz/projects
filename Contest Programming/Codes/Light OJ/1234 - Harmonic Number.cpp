#include <bits/stdc++.h>
using namespace std;

double ans[1000002];
int main()
{
    ans[0]=0;
    for(int i=1; i<1000001; i++)
    {
        ans[i]=ans[i-1]+1.0/(double)i;
    }
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        if(n<1000001)  printf("Case %d: %.9f\n", t, ans[n]);
        else    printf("Case %d: %.9f\n", t, log(n+0.5)+.5772156649);
    }

    return 0;
}
