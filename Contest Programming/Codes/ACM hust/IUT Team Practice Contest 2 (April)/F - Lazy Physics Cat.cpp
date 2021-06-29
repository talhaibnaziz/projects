#include <bits/stdc++.h>
using namespace std;

#define pi 2*acos(0.0)
int main()
{
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        double l, a, area1, area2;
        cin>>l>>a;
        a = a*pi/180.0;
        area1 = l*l*sin(a)/2.0;
        area2 = pi*l*l*(a/(2*pi));
        printf("%.6f\n", area2-area1);
    }

    return 0;
}
