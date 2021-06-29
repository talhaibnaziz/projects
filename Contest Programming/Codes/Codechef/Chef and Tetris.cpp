#include <bits/stdc++.h>
using namespace std;
int n;
int ar[10010], br[10010];
bool vis[10010];
int rec(int i)
{
    cout<<i<<' '<<ar[i-1]<<endl;
    //base cases
    if(i==n)    return ar[n-1];
    if(i==0 && i==(n-1))    return ar[0]+br[0];
    if(i==(n-1))
    {
        int a=-1, b=-1;
        if(!vis[i-1])
        {
            if(ar[i]+br[i-1]==ar[i-1])
            {
                ar[i]+=br[i-1];
                vis[i-1]=1;
                a=rec(i+1);
                ar[i]-=br[i-1];
                vis[i-1]=0;
            }
        }
        if(!vis[i])
        {
            if(ar[i]+br[i]==ar[i-1])
            {
                ar[i]+=br[i];
                vis[i]=1;
                b=rec(i+1);
                ar[i]-=br[i];
                vis[i]=0;
            }
        }
    }
    if(i==0)
    {
        int a=-1, b=-1;
        if(!vis[i])
        {
            ar[i]+=br[i];
            vis[i]=1;
            a=rec(i+1);
            ar[i]-=br[i];
            vis[i]=0;
        }
        if(!vis[i+1])
        {
            ar[i]+=br[i+1];
            vis[i+1]=1;
            b=rec(i+1);
            ar[i]-=br[i+1];
            vis[i+1]=0;
        }
        return max(a, b);
    }
    int a=-1, b=-1, c=-1;
    //normal case
    if(!vis[i-1])
    {
        if(ar[i]+br[i-1]==ar[i-1])
        {
            ar[i]+=br[i-1];
            vis[i-1]=1;
            a=rec(i+1);
            ar[i]-=br[i-1];
            vis[i-1]=0;
        }
    }
    if(!vis[i])
    {
        if(ar[i]+br[i]==ar[i-1])
        {
            ar[i]+=br[i];
            vis[i]=1;
            b=rec(i+1);
            ar[i]-=br[i];
            vis[i]=0;
        }
    }
    if(!vis[i+1])
    {
        if(ar[i]+br[i+1]==ar[i-1])
        {
            ar[i]+=br[i+1];
            vis[i+1]=1;
            c=rec(i+1);
            ar[i]-=br[i+1];
            vis[i+1]=0;
        }
    }
    return max(a,max(b,c));
}
int main()
{
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n;
        for(int i=0; i<n; i++)  cin>>br[i];
        for(int i=0; i<n; i++)  cin>>ar[i];
        memset(vis, 0, sizeof(vis));
        cout<<rec(0)<<"\n";
    }

    return 0;
}
