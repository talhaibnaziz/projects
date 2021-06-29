#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, y, r;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>x>>y>>r;
        int dis1 = x*x+y*y;
        int dis2 = r*r;
        double d1 = sqrt((double)dis1);
        double d2 = sqrt((double)dis2);
        printf("%.2f %.2f\n", d2-d1, d2+d1);
    }

    return 0;
}
