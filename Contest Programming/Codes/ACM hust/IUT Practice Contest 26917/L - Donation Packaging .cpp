#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=0, cases;
    cin>>cases;
    long long int sa=0, sb=0, sc=0;
    long long int a, b, c;
    while(t++<cases)
    {
        cin>>a>>b>>c;
        sa += a;
        sb += b;
        sc += c;
        int n = min(min(sa,sb),sc);
        if(n<30)    cout<<"NO\n";
        else
        {
            cout<<n<<"\n";
            sa -= n;
            sb -= n;
            sc -= n;
        }
    }

    return 0;
}
