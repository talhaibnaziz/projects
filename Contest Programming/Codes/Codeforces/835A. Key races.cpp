#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int s, v1, v2, t1, t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int ans1 = s*v1 + 2*t1;
    int ans2 = s*v2 + 2*t2;
    if(ans1<ans2)   cout<<"First";
    else if(ans2<ans1)  cout<<"Second";
    else    cout<<"Friendship";

    return 0;
}
