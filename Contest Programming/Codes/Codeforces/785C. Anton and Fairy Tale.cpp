#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m, n;
    cin>>n>>m;
    if(m>=n)
    {
        cout<<n;
    }
    else
    {
        long long grainleft;
        grainleft = n-m;
        long long days;
        days=sqrt(2*grainleft);
        while((days*(days+1))<(2*grainleft))    days++;
        cout<<days+m;
    }

    return 0;
}
