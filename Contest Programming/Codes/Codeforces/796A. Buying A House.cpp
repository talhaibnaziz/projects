#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k, a[110];
    cin>>n>>m>>k;
    int ans=1000000;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]!=0 && a[i]<=k && (abs(i+1-m)*10)<ans)    ans=abs(i+1-m)*10;
        //cout<<i<<' '<<ans<<endl;
    }
    cout<<ans;

    return 0;
}
