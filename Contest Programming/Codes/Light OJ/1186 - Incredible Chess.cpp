#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        int w[305], b[305], ar[305];
        for(int i=0; i<n; i++)  scanf("%d", &w[i]);
        for(int i=0; i<n; i++)  scanf("%d", &b[i]);
        for(int i=0; i<n; i++)  ar[i]=b[i]-w[i]-1;
        int xorsum=ar[0];
        for(int i=1; i<n; i++)  xorsum = xorsum ^ ar[i];
        if(xorsum>0)    printf("Case %d: white wins\n", t);
        else    printf("Case %d: black wins\n", t);
    }

    return 0;
}
