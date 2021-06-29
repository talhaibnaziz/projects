#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char ar[100010];

    int cnt=0, poktype[130];
    memset(poktype, 0, sizeof(poktype));
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
        if(poktype[(int)ar[i]]==0)    cnt++;
        poktype[(int)ar[i]]++;
    }
    int i=0, j=0;
    int vis[130];
    memset(vis, 0, sizeof(vis));
    int caught=0;
    int ans=100010;
    while(1)
    {
        if(cnt==caught)
        {
            //cout<<cnt<<' '<<i<<' '<<j<<endl;
            ans=min(ans, j-i);
            vis[(int)ar[i]]--;
            if(vis[(int)ar[i]]==0)  caught--;
            i++;
            continue;
        }
        if(j==n)    break;
        if(vis[(int)ar[j]]==0)  caught++;
        vis[(int)ar[j]]++;
        j++;
    }
    cout<<ans;

    return 0;
}
