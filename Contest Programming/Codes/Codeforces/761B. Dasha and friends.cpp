#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    int arra[55],arrb[55];
    scanf("%d %d", &n, &l);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arra[i]);
    }

    bool possible = 1;
    bool bara[105], barb[105];
    memset(barb, 0, sizeof barb);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arrb[i]);
        barb[arrb[i]]=1;
    }
    for(int i=0; i<l; i++)
    {
        possible=1;
        memset(bara, 0, sizeof bara);
        for(int ii=0; ii<n; ii++)
        {
            bara[(arra[ii]+i)%l]=1;
        }
        for(int ii=0; ii<l; ii++)
        {
            if(bara[ii]^barb[ii])
            {
                possible = 0;
                break;
            }
        }
        if(possible)    break;
    }
    if(possible)    printf("YES");
    else    printf("NO");

    return 0;
}
