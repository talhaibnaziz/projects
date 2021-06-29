#include <bits/stdc++.h>
using namespace std;
int ar[100010];

int findleft(int limit, int s)
{
    int lft=0, rt=s-1, mid;
    while(lft<rt)
    {
        mid=(lft+rt)/2;
        if(ar[mid]>limit)   rt=mid;
        else if(ar[mid]<limit)  lft=mid+1;
        else return mid;
    }
    return lft;
}
int findright(int limit, int s)
{
    int lft=0, rt=s-1, mid;
    while(lft<rt)
    {
        if((lft+rt)%2==0)   mid=(lft+rt)/2;
        else mid=(lft+rt)/2+1;
        if(ar[mid]>limit)   rt=mid-1;
        else if(ar[mid]<limit)  lft=mid;
        else return mid;
    }
    return rt;
}
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, q, p, a, b;
        scanf("%d %d", &n, &q);
        for(int i=0; i<n; i++)  scanf("%d", &ar[i]);
        printf("Case %d:\n", t);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d", &a, &b);
            int lft, rt, ans;
            if(a>ar[n-1] || b<ar[0])    ans=0;
            else    ans=(rt=findright(b, n))-(lft=findleft(a, n))+1;
            printf("%d\n", ans);
        }
    }

    return 0;
}
