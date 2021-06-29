#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long s, t, x;
    cin>>t>>s>>x;
    bool flag=0;
    if(x<t) flag=0;
    else if(x==t)    flag=1;
    else
    {
        x-=t;
        if(x%s==0 || (x%s==1 && x!=1))    flag=1;
    }
    if(flag)    printf("YES");
    else printf("NO");
}
