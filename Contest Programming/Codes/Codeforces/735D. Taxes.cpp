#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int val = sqrt(n);
    bool p = 1;
    for(int i=2; i<=val; i++)
    {
        if(n%i==0)
        {
            p = 0;
            break;
        }
    }
    if(p)
    {
        printf("1");
    }
    else if(n%2==0)
    {
        printf("2");
    }
    else
    {
        int m=n-2;
        int val1 = sqrt(m);
        bool p1 = 1;
        for(int i=2; i<=val1; i++)
        {
            if(m%i==0)
            {
                p1 = 0;
                break;
            }
        }
        if(p1)
        {
            printf("2");
        }
        else    printf("3");
    }

    return 0;
}
