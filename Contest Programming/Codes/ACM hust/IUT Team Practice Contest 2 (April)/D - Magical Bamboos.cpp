#include <bits/stdc++.h>
using namespace std;

int h[100005];

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        bool possible = 1;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &h[i]);
            if(i>0 && abs(h[i]-h[i-1])%2)   possible = 0;
        }
        if(possible)    printf("yes\n");
        else    printf("no\n");
    }

    return 0;
}
