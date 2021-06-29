#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <climits>

using namespace std;


int sub(int ar[],int n)
{
    if(n==1)
    {
        return ar[0];
    }
    int m=n/2;
    int left_max=sub(ar,m);
    int right_max=sub(ar+m,n-m);

    int left=INT_MIN,right=INT_MIN,sum=0;

    for(int i=m;i<n;i++)
    {
        sum=sum+ar[i];
        right=max(right,sum);
    }
    sum=0;
    for(int i=m-1;i>=0;i--)
    {
        sum=sum+ar[i];
        left=max(left,sum);
    }
    int ans=max(left_max,right_max);
    return max(ans,right+left);
}

int main()
{
    int n;
    cin>>n;
    int ara[100];
    for(int i=0;i<n;i++)
        cin>>ara[i];
    cout<<sub(ara,n)<<endl;

    return 0;
}
