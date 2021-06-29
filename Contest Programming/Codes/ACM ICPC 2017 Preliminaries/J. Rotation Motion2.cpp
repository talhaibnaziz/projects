#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define exp .0000000001
#define pi 2*acos(0.0)

double mymod(double angle)
{
    int a=angle/(2*pi);
    if(angle>0) return (angle-2.0*pi*(double)a);
    else    return (angle+2.0*pi*(double)a);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout<<sin(-pi)<<endl;
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        double bx,by, ax, w,t;
        cin>>bx>>by>>ax>>w>>t;

        double theta=atan(by/bx);
        if(by<0 && bx<0)
            theta = theta + pi;
        else if(bx<0)
            theta = pi + theta;
        double ghur=w*t;
        ghur=theta+ghur;
        ghur = mymod(ghur);
        double ghur180;
        if(ghur<0)  ghur += 2.0*pi;
        if(ghur>pi)
        {
            ghur180 = ghur-pi;
            ghur180 = pi-ghur180;
        }
        else ghur180 = ghur;
        //cout<<ghur<<' '<<ghur180<<endl;
        double r2=bx*bx + by*by;
        double c2=(bx-ax)*(bx-ax) + by*by;
        double cos2 = cos(ghur180);
        cos2 = cos2*cos2;
        double lo = r2;
        double hi = c2+r2+2*c2*r2;
        double mid;
        double tcos2;
        for(int i=0; i<1000; i++)
        {
            mid = (lo+hi)/2;
            tcos2 = (r2+mid*mid-c2);
            tcos2 *= tcos2;
            tcos2 /= (4*mid*mid*r2);
            if(tcos2>cos2)
                lo = mid;
            else
                hi = mid;
        }

        cout<<"Case "<<tc<<": "<<fixed<<setprecision((6))<<mid<<"\n";

    }


}
