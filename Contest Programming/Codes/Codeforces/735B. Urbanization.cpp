#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, n1, n2, ar[100005];
    scanf("%d %d %d", &n, &n1, &n2);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }
    sort(ar, ar+n);
    int rt = min(n1, n2), lft = max(n1, n2);
    double lftav=0, rtav=0;
    for(int i = n-1, j=0; j<rt; i--, j++)
    {
        rtav += (double) ar[i];
    }
    rtav/=(double)rt;
    for(int i = n-1-rt, j=0; j<lft; i--, j++)
    {
        lftav += (double) ar[i];
    }
    lftav/=(double)lft;
    printf("%f", lftav + rtav);

    return 0;
}
