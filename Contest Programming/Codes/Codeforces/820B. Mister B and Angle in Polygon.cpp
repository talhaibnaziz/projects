#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double a;
    cin>>n>>a;
    double angle = 180;
    angle = angle/(double)n;
    double b, minangle = 500;
    int ans;
    for(int i=3; i<=n; i++)
    {
        b = angle * (double)(n-i+1);
        if(abs(b-a)<minangle)
        {
            minangle = abs(b-a);
            ans = i;
        }
    }
    cout<<"1 2 "<<ans;

    return 0;
}
