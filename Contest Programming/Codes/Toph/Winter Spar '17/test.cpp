#include <bits/stdc++.h>
using namespace std;

long long BigMod(long long B, long long P, long long M)
{
    long long R = 1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

int main()
{
    cout<<((2%1000003)*(BigMod(6, 1000003-2, 1000003)))%1000003<<endl;
}
