#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long cases, t=0;
    cin>>cases;
    while(t++<cases)
    {
        long long n;
        cin>>n;
        long long a, b, c, d, ans=0;
        for(d=0; d*d*d*d<=n; d++)
        {
            for(c=0; c*c*c+d*d*d*d<=n; c++)
            {
                long long rem=n-d*d*d*d-c*c*c;
                long long lim=sqrt(rem);
                ans+=lim+1;
                //cout<<lim<<' '<<c<<' '<<d<<endl;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
