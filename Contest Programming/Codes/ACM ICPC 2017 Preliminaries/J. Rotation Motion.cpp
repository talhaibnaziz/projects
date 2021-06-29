#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define exp .0000000001
#define pi 2*acos(0.0)

double mymod(double angle)
{
    int a=angle/(2*pi);
    return angle-2.0*pi*(double)a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout<<sin(-pi)<<endl;
    cout<<fixed<<setprecision(9)<<pi<<endl;
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        double bx,by, ax, w,t;
        cin>>bx>>by>>ax>>w>>t;

        double theta;
        if(bx!=0)   theta=atan(by/bx);
        else    theta=pi/2.0;
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
        double r=sqrt(bx*bx + by*by);
        double c=sqrt( (bx-ax)*(bx-ax) + by*by );
        double temp= sin(ghur180)*r/c;
        double angb= asin(temp);
        //cout<<pi<<' '<<angb<<' '<<ghur180<<endl;
        double anga= pi-angb-ghur180;
        double ans=sin(anga)*c/sin(ghur180);
        cout<<"Case "<<tc<<": "<<fixed<<setprecision((6))<<ans<<"\n";

    }


}
