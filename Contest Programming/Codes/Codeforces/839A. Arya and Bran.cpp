#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    int a[105];
    cin>>n>>k;
    for(int i=0; i<n; i++)  cin>>a[i];
    int days = -1, sum=0;
    for(int i=0; i<n; i++)
    {
        sum += a[i];
        if(sum<8)
        {
            k-=sum;
            sum=0;
        }
        else
        {
            k-=8;
            sum-=8;
        }
        if(k<1)
        {
            days=i+1;
            break;
        }
    }
    cout<<days;

    return 0;
}
