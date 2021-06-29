#include <bits/stdc++.h>
using namespace std;

long long m, a, b, r, ans;
long long ar[205];

long long findleft(long long sum, long long lft)
{
    if((sum+ar[lft])>=a)  return lft;
    long long rt=m-1, mid;
    while(lft<=rt)
    {
        mid=(lft+rt)/2;
        //cout<<sum<<' '<<mid<<endl;
        if((sum+ar[mid])>=a && (sum+ar[mid-1])<a)   return mid;
        if(sum+ar[mid]>a)   rt=mid-1;
        else if(sum+ar[mid]<a)  lft=mid+1;
    }

    return -1;
}
long long findright(long long sum, long long lft)
{
    if((sum+ar[m-1])<=b) return m-1;
    long long rt=m-1, mid;
    while(lft<rt)
    {
        mid=(lft+rt)/2;
        if((sum+ar[mid])<=b && (sum+ar[mid+1])>b)   return mid;
        if(sum+ar[mid]>b)   rt=mid-1;
        else if(sum+ar[mid]<b)  lft=mid+1;
    }

    return -1;
}
int main()
{
    freopen("in.txt", "r", stdin);
    long long cases, t=0;
    scanf("%lld", &cases);
    while(t++<cases)
    {
        scanf("%lld", &m);
        for(long long i=0; i<m; i++)  scanf("%lld", &ar[i]);
        sort(ar, ar+m);
        scanf("%lld %lld", &a, &b);
        r=0, ans=0;
        for(long long i=0; i<m; i++)
        {
            r+=ar[i];
            for(long long j=i; j<m; j++)
            {
                r+=ar[j];
                for(long long k=j; k<m; k++)
                {
                    r+=ar[k];
                    long long lft=findleft(r, k), rt=findright(r, k);
                    if(lft!=-1 && rt!=-1)
                    {
                        //printf("%lld %lld %lld %lld %lld\n", i, j, k, lft, rt);
                        ans+=rt-lft+1;
                    }
                    r-=ar[k];
                }
                r-=ar[j];
            }
            r-=ar[i];
        }
        printf("Case %lld: %lld\n", t, ans);
    }

    return 0;
}
