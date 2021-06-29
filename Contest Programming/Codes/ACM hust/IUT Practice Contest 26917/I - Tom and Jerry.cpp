#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=0, cases;
    cin>>cases;
    double mul = 45.0/0.70685835;
    mul /= 100;
    while(t++<cases)
    {
        double r, v;
        cin>>r>>v;
        cout<<"Case "<<t<<": "<<fixed<<setprecision(7)<<r*log(9999999999999)/v<<"\n";
    }

    return 0;
}
