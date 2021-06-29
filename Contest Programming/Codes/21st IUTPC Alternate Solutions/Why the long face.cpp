#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int tc=0, t;
    double bc, cd, ad, xlow, xmid1, xmid2, xhigh;
    double sand, grass, left_val, right_val;
    cin>>t;
    while(tc++<t)
    {
        cin>>bc>>cd>>ad;
        xlow = 0.0;
        xhigh = bc;
        for(int i=0; i<100; i++)
        {
            xmid1 = xlow+((xhigh-xlow)/3.0);
            xmid2 = xlow+(2.0*(xhigh-xlow)/3.0);

            sand = xmid1*xmid1 + ad*ad;
            grass = (bc-xmid1)*(bc-xmid1) + cd*cd;
            left_val = 2*sqrt(sand)+sqrt(grass);

            sand = xmid2*xmid2 + ad*ad;
            grass = (bc-xmid2)*(bc-xmid2) + cd*cd;
            right_val = 2*sqrt(sand)+sqrt(grass);

            if(left_val<right_val)
                xhigh = xmid2;
            else    xlow = xmid1;
        }

        cout<<sqrt(sand)+sqrt(grass)<<endl;
    }

    return 0;
}
