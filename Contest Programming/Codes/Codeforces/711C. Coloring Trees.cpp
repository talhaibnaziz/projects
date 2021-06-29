#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"I am here"<<endl;
long long c[110];
long long n, m, k;
long long p[110][110];

long long rec(long long tree, long long paint)
{
    //cout<<tree<<' '<<paint<<endl;
    //for(long long i=0; i<n; i++)  cout<<c[i];
    //cout<<endl;
    bool flag=0;
    long long t, ans=999999999999999;
    for(long long i=tree+1; i<n; i++)
    {
        if(c[i]==0)
        {
            flag=1;
            t=i;
            break;
        }
    }
    if(flag)
    {
        for(long long i=0; i<m; i++)
        {
            c[t]=i+1;
            ans=min(ans,rec(t, paint+(long long)p[t][i]));
            c[t]=0;
        }
        return ans;
    }
    else
    {
        long long cnt=1;
        for(long long i=1; i<n; i++)
        {
            if(c[i]!=c[i-1])    cnt++;
        }
        //cout<<"beauty: "<<cnt<<endl;
        if(cnt==k)  return paint;
        else return 999999999999999;
    }
}

int main()
{
    cin>>n>>m>>k;
    for(long long i=0; i<n; i++)  cin>>c[i];
    for(long long i=0; i<n; i++)
        for(long long j=0; j<m; j++)  cin>>p[i][j];
    long long ans;
    ans=rec(-1, 0);
    if(ans==999999999999999) printf("-1");
    else cout<<ans;
    return 0;
}
