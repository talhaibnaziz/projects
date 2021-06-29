#include <bits/stdc++.h>
using namespace std;

string arr[500005];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i]>arr[i+1])
        {
            int j, lim = min(arr[i].size(), arr[i+1].size());
            for(j=1; j<lim; j++)
            {
                if(arr[i][j]>arr[i+1][j])
                {
                    arr[i].erase(arr[i].begin()+j, arr[i].end());
                    break;
                }
            }
            if(j==lim && (arr[i].size()>arr[i+1].size()))   arr[i].erase(arr[i].begin()+arr[i+1].size(), arr[i].end());
        }
    }
    for(int i=0; i<n; i++)  cout<<arr[i]<<'\n';

    return 0;
}
