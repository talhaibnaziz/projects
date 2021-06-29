#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, l, r;
    cin>>a>>b>>l>>r;
    if((r-l+1)==(a+b))
    {
        //when starts from mister B
        if(l%(a+b)>=1 && l%(a+b)<=b)  cout<<a+1;
        else    cout<<a;
    }
    else if((r-l+1)>(a+b))
    {
        if(b>=a)
        {
            if(l%(a+b)>=1 && l%(a+b)<=b)  cout<<a+1;
            else    cout<<a;
        }
        else
        {

        }
    }
    else
    {
        if(l%(a+b)>=1 && r%(a+b)<=b)    cout<<"1";
        else if(r%(a+b)<=b) cout<<(r-l+1)-b;
        else if(l%(a+b)>=1 && l%(a+b)<=b) cout<<
    }

    return 0;
}
