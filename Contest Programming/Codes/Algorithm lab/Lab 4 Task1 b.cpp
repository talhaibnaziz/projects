#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ar[100];
    int n;
    cin>>n;
    bool flag=0, vis[100];
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++)  cin>>ar[i];
    vis[ar[1]]=1;
    for(int i=0; i<n-2; i++)
    {
        if(i>0) vis[ar[i]]=0;
        for(int j=i+2; j<n; j++)
        {
            vis[ar[j-1]]=1;
            int d=ar[i]+ar[j];
            if(d%2==0)
            {
                d=d/2;
                if(vis[d])
                {
                    flag=1;
                    break;
                }
            }
            else continue;
        }
        if(flag==1) break;
    }
    if(flag)    cout<<"YES";
    else cout<<"NO";

    return 0;
}
