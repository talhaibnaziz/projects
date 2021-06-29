#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int m, n;
        long long ar[55];
        long long in;
        scanf("%d %d", &m, &n);
        for(int i=0; i<m; i++)
        {
            ar[i]=0;
            for(int j=0; j<n; j++)
            {
                scanf("%lld", &in);
                ar[i]+=in;
            }
        }
        long long xorsum=ar[0];
        for(int i=1; i<m; i++)  xorsum = xorsum ^ ar[i];
        if(xorsum>0)    printf("Case %d: Alice\n", t);
        else    printf("Case %d: Bob\n", t);
    }

    return 0;
}
