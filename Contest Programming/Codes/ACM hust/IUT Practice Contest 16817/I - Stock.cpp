#include <bits/stdc++.h>
using namespace std;

pair <long long, int> arr[1000005];
long long a[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=0, cases, n;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            arr[i].first = a[i];
            arr[i].second = i;
        }
        sort(arr, arr+n);
        for(int i=0; i<n/2; i++)    swap(arr[i], arr[n-i-1]);
        long long ans = 0;
        long long cnt = 0;
        int idx = 0;
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<' '<<arr[idx].first<<'('<<arr[idx].second<<')'<<endl;
            if(a[i]==arr[idx].first)
            {
                ans += cnt*a[i];
                cnt = 0;
            }
            else if(i<arr[idx].second)  cnt++;
            else if(i>arr[idx].second)
            {
                while(i>arr[idx].second)    idx++;
                i--;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
