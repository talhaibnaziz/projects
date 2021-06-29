#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(a%b==0)  return b;
    if(b%a==0)  return a;
    if(a>b) return GCD(b, a%b);
    else return GCD(a, b%a);
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<GCD(a, b);

    return 0;
}
