#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    int n;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++)
    {
        string kill, rep;
        cin>>kill>>rep;
        cout<<a<<' '<<b<<'\n';
        if(kill==a) a=rep;
        else    b=rep;
    }
    cout<<a<<' '<<b<<'\n';

    return 0;
}
