#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arra[10]={0}, arrb[10]={0}, tot[10]={0};
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        arra[a]++;
        tot[a]++;
    }
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        arrb[a]++;
        tot[a]++;
    }
    bool flag = 1;
    for(int i=1; i<6; i++)
    {
        if(tot[i]%2)
        {
            flag = 0;
            break;
        }
    }
    int ans = 0;
    if(flag)
    {
        for(int i=1; i<6; i++)
        {
            if(arra[i]>arrb[i]) ans+=(arra[i]-arrb[i]);
            else    ans+=arrb[i]-arra[i];
        }
        printf("%d", ans/4);
    }
    else    printf("-1");

    return 0;
}
