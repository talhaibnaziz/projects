#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n, l, v1, v2, k;
    cin>>n>>l>>v1>>v2>>k;
    double ans=0;
    if(v1>=v2)  ans=(double)l/(double)v1;
    else
    {
        double dis, tim, pos=0;
        while(1)
        {
            dis=l-pos;
            tim=dis/v2;
            pos+=tim*v1;
            n-=k;
            ans+=tim;
            if(n<=0)    break;

            dis=l-pos;
            tim=dis/(v1+v2);
            pos+=tim*v1;
            ans+=tim;
        }
    }
    cout<<ans;

    return 0;
}
