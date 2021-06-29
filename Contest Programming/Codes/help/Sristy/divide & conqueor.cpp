#include <iostream>
#include <climits>

using namespace std;


int max_sum(int ara[],int n)
{
    if(n==1)
    {
        return ara[0];
    }
    int m=n/2;
    int left=max_sum(ara,m);
    int right=max_sum(ara+m,n-m);

    int left_sum=INT_MIN,right_sum=INT_MIN,sum=0;

    for(int i=m;i<n;i++)
    {
        sum=sum+ara[i];
        right_sum=max(right_sum,sum);
    }
    sum=0;
    for(int i=m-1;i>=0;i--)
    {
        sum=sum+ara[i];
        left_sum=max(left_sum,sum);
    }
    int ans=max(left,right);
    return max(ans,right_sum+left_sum);
}

int main()
{
    int n;
    cin>>n;
    int ara[4];
    for(int i=0;i<n;i++)
        cin>>ara[i];
    cout<<max_sum(ara,n)<<endl;
}
