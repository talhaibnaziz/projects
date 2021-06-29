#include <bits/stdc++.h>
using namespace std;
long long ar[100010];
string s;

long long cnt(long long lft, long long rt)
{
    //cout<<lft<<' '<<rt<<endl;
    if(rt==(lft+1)) return 0;
    if((ar[lft+1]-ar[lft])<(ar[rt]-ar[rt-1]))   return (ar[lft+1]-ar[lft])+cnt(lft+1, rt);
    else return (ar[rt]-ar[rt-1])+cnt(lft, rt-1);
}
int main()
{
    long long t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        long long n, i, j=0;
        cin>>n;
        cin>>s;
        for(i=0; i<n; i++)  cin>>ar[i];
        for(i=0; i<n; i++)  if(s[i]=='1')   break;
        long long ans=0;
        ans+=ar[i]-ar[0];
        //cout<<ans<<endl;
        while(1)
        {
            for(j=i+1; j<n; j++)
            {
                if(s[j]=='1')
                {
                    ans+=cnt(i, j);
                    break;
                }
            }
            //cout<<i<<"  "<<j<<endl;
            if(j==n)    break;
            i=j;
        }
        //cout<<ans<<endl;
        ans+=ar[n-1]-ar[i];
        printf("%d\n", ans);
    }

    return 0;
}
/*
2
2
01
1 2
3
100
1 5 6
*/
