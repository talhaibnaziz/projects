#include <bits/stdc++.h>
using namespace std;

map <int, bool> mp;
int arr[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t, tc=0, cnt;
    cin>>t;
    while(tc++<t)
    {
        int n;
        cin>>n;
        mp.clear();
        cnt = 0;
        for(int i=0; i<n; i++)
        {
            int c;
            cin>>c;
            if(mp[c]==0)
            {
                mp[c]=1;
                arr[cnt++]=c;
            }
        }
        sort(arr, arr+cnt);
        cout<<"Set #"<<tc<<": ";
        for(int i=0; i<cnt; i++)
        {
            int start = i;
            int fin = i;
            while(i!=(cnt-1) && arr[i]==(arr[i+1]-1))
            {
                i++;
                fin++;
            }
            if(start==fin)  cout<<arr[start];
            else    cout<<arr[start]<<'-'<<arr[fin];
            if(i!=(cnt-1))  cout<<", ";
        }
        cout<<"\n\n";
    }

    return 0;
}
