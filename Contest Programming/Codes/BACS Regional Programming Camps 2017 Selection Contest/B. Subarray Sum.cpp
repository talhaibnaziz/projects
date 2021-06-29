#include <bits/stdc++.h>
using namespace std;

long long arr[5005], ans;
int n;

long long maxsubarray()
{
    long long maxsum = -9999999999999;
    long long sum=0;
    int lft=0, rt=0;
    while(rt<n)
    {
        //cout<<sum<<' '<<lft<<' '<<rt<<endl;
        if(sum<0)
        {
            sum = 0;
            lft=rt;
        }
        else
        {
            sum += arr[rt];
            if(sum>maxsum)
            {
                maxsum = sum;
            }
            rt++;
        }
    }
    return maxsum;
}
 void rec(int k, int pos)
 {
     if(k==0)
     {
        ans = max(ans, maxsubarray());
        return;
     }
     //cout<<k<<' '<<pos<<endl;
     for(int i=pos; i<n; i++)
     {
         if(arr[i]<0)
         {
             int tmp = arr[i];
             arr[i]=0;
             rec(k-1, i+1);
             arr[i]=tmp;
         }
     }
     ans = max(ans, maxsubarray());
 }
int main()
{
    int t=0, k, cases;
    cin>>cases;
    while(t++<cases)
    {
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        ans = -9999999999999;
        rec(k, 0);
        printf("Case %d: %lld\n", t, ans);
    }

    return 0;
}

/*
1
50 50
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
