#include <bits/stdc++.h>
using namespace std;

long long fuelnode[100005];
long long fueledge[100005];
long long arr[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, t=0;
    while(1)
    {
        cin>>n;
        if(n==0)    break;
        t++;
        for(long long i=0; i<n; i++)    cin>>fuelnode[i];
        for(long long i=0; i<n; i++)    cin>>fueledge[i];
        long long sum = 0, minval = 999999999999;
        for(long long i=0; i<n; i++)
        {
            arr[i]=fuelnode[i]-fueledge[i];
            sum+=arr[i];
            minval = min(minval, sum);
        }
        cout<<"Case "<<t<<":";
        if(minval>=0)   cout<<" 1";
        for(int i=1; i<n; i++)
        {
            minval -= arr[i-1];
            if(minval>=0)   cout<<" "<<i+1;
        }
        cout<<"\n";
    }
    return 0;
}
