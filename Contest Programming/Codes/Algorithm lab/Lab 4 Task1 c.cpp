#include <bits/stdc++.h>
using namespace std;
int ar[100];
bool vis[100];
bool rec(int i, int j)
{
    cout<<i<<' '<<j<<endl;
    if(j==(i+1))    return 0;
    vis[i]=0;
    vis[j]=0;
    int d=ar[i]+ar[j];
    if(d%2==0)
    {
        d=d/2;
        if(vis[d])  return 1;
    }
    return rec(i+1, j) || rec(i, j-1);
}
int main()
{
    int n;
    cin>>n;
    bool flag=0;
    for(int i=0; i<n; i++)  cin>>ar[i];
    memset(vis, 1, sizeof(vis));
    flag=rec(0, n-1);
    if(flag)    cout<<"YES";
    else cout<<"NO";

    return 0;
}
