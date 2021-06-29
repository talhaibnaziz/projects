#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int k;
        scanf("%d", &k);
        bool flag=1;
        int ar[105];
        for(int i=0; i<k; i++)
        {
            scanf("%d", &ar[i]);
            if(ar[i]!=1)    flag=0;
        }
        if(flag)
        {
            if(k%2==0)  printf("Case %d: Alice\n", t);
            else    printf("Case %d: Bob\n", t);
            continue;
        }
        int xorsum=ar[0];
        for(int i=1; i<k; i++)  xorsum = xorsum ^ ar[i];
        if(xorsum>0)    printf("Case %d: Alice\n", t);
        else    printf("Case %d: Bob\n", t);
    }

    return 0;
}
