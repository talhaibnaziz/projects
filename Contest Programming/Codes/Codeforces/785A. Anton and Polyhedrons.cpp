#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        if(s=="Tetrahedron")    ans+=4;
        else if(s=="Cube")  ans+=6;
        else if(s=="Octahedron")    ans+=8;
        else if(s=="Dodecahedron")  ans+=12;
        else    ans+=20;
    }
    cout<<ans;

    return 0;
}
