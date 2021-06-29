#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    cin>>cases;
    while(t<cases)
    {
        double r;
        cin>>r;
        double len=1.75*(sqrt(15.0)/4.0+sqrt(3.0)/2.0)-(sqrt(15.0)/4.0*0.25);
        len = len/(sqrt(15.0)/4.0+sqrt(3.0)/2.0);
        len = len * r;
        cout<<"Case "<<++t<<": "<<len<<endl;
    }

    return 0;
}
