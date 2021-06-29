#include <bits/stdc++.h>
using namespace std;

string arr[20];
int ans[20], n, show[20];

int cmp()
{
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]=='1' && (ans[j]<ans[i]))   cnt++;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        cin>>n;
        if(n==0)    break;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            ans[i]=i;
            show[i]=i;
        }
        int minvalue = cmp();
        while(next_permutation(ans, ans+n))
        {
            int val = cmp();
            if(val<minvalue)
            {
                minvalue = val;
                for(int i=0; i<n; i++)  show[i]=ans[i];
            }
        }
        for(int i=0; i<n-1; i++)    cout<<show[i]<<' ';
        cout<<show[n-1]<<"\n";
    }

    return 0;
}

