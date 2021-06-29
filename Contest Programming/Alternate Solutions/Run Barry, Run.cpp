#include <bits/stdc++.h>
using namespace std;

int arr[300005];
int arr2[300005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        for(int i=0, j=n-1; i<n; i++, j--)
        {
            arr2[i] = arr[j];
        }
        int ans = 1, mx = 0;
        for(int i=1; i<n; i++)
        {
            mx = max(arr2[i-1]+i,mx);
            if(mx<=arr2[i]+n)    ans++;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
