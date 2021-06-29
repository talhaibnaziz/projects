#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(long long i=1000000; i<10000000; i++)
    {
        if(i==(i*i)%10000000)    cout<<i<<' '<<i*i<<endl;
    }
    return 0;
}
