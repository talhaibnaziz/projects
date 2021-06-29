#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c, v1, v0, a, l;
    cin>>c>>v0>>v1>>a>>l;
    int ans = 1;
    c -= v0;
    v0 += a;
    if(v0>v1)   v0 = v1;
    while(c>0)
    {
        //cout<<ans<<' '<<c<<' '<<v0<<' '<<l<<' '<<v1<<endl;
        //can read physically
        c -= (v0-l);
        v0 += a;
        if(v0>v1)   v0 = v1;
        ans++;
    }
    cout<<ans;

    return 0;
}
