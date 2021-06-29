#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long arr[100005], n, k, mx = -1111111111111, mn=1111111111111;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    if(k==1) cout<<mn;
    else if(k==2)
    {
        if(arr[0]==mx || arr[n-1]==mx)  cout<<mx;
        else
        {
            mx = -1111111111111, mn=1111111111111;
            for(int i=0; i<n-1; i++)
            {
                mn = min(mn, arr[i]);
                mx = max(mn, mx);
            }
            mn=1111111111111;
            for(int i=n-1; i>0; i--)
            {
                mn = min(mn, arr[i]);
                mx = max(mn, mx);
            }
            cout<<mx;
        }
    }
    else    cout<<mx;

    return 0;
}
