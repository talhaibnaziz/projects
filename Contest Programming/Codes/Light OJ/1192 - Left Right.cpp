#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int k;
        int pos[205];
        int ar[105];
        scanf("%d", &k);
        for(int i=0; i<2*k; i++)
        {
            scanf("%d", &pos[i]);
            if(i%2==1)  ar[i/2]=pos[i]-pos[i-1]-1;
        }
        int xorsum=ar[0];
        for(int i=1; i<k; i++)  xorsum = xorsum ^ ar[i];
        if(xorsum>0)    printf("Case %d: Alice\n", t);
        else    printf("Case %d: Bob\n", t);
    }

    return 0;
}
