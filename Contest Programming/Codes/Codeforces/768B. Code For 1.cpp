#include <bits/stdc++.h>
using namespace std;

bool findrange(long long pos, long long lim, long long num)
{
    long long l=1, r=lim, mid;
    while(l!=r)
    {
        mid = (l+r)/2;
        if(mid==pos)    return num%2;
        else if(pos<mid)    r=mid-1;
        else    l=mid+1;
        num/=2;
    }
    return num%2;
}
int main()
{
    long long n, l, r, lim;
    int ans=0;
    cin>>n>>l>>r;
    if(n==0)    cout<<"0";
    else
    {
        lim = log2(n);
        //cout<<lim<<endl;
        lim = pow(2, lim+1)-1;
        //cout<<lim<<endl;
        for(long long i=l; i<=r; i++)
        {
            ans+=findrange(i, lim, n);
        }
        cout<<ans;
    }

    return 0;
}
