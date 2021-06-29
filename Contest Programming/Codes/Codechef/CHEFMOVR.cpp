#include <bits/stdc++.h>
using namespace std;

long long n, d, arr[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n>>d;
        long long sum = 0, avg;
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
            sum += arr[i];
        }
        long long ans = 0;
        if(sum%n==0)
        {
            avg = sum/n;
            for(int i=1; i<(d+1); i++)
            {
                //cout<<i<<endl;
                for(int j=i; j<=(n-d); j+=d)
                {
                    if(arr[j]<avg)
                    {
                        ans += avg-arr[j];
                        arr[j+d] -= avg-arr[j];
                        arr[j] += avg-arr[j];
                    }
                    else if(arr[j]>avg)
                    {
                        ans -= avg-arr[j];
                        arr[j+d] -= avg-arr[j];
                        arr[j] += avg-arr[j];
                    }

                    //cout<<ans<<' '<<arr[j]<<' '<<arr[j+d]<<endl;
                }
            }
        }
        else ans = -1;
        for(int i=1; i<=n; i++) if(arr[i]!=avg) ans = -1;
        cout<<ans<<"\n";
    }

    return 0;
}
