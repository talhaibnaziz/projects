#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int r, c, in, xorsum;
        scanf("%d %d", &r, &c);
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                scanf("%d", &in);
                if(i==0 && j==0)
                {
                    xorsum = in;
                    int lim=(r-i-1)+(c-j-1)-1;
                    for(int k=0; k<lim; k++)    xorsum = xorsum ^ in;
                }
                else
                {
                    int lim=(r-i-1)+(c-j-1);
                    for(int k=0; k<lim; k++)    xorsum = xorsum ^ in;
                }
            }
        }
        if(r==1 && c==1)    xorsum=0;
        if(xorsum==0)   printf("Case %d: lose\n", t);
        else    printf("Case %d: win\n", t);
    }

    return 0;
}
