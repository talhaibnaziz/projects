#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, k;
    cin>>n>>m>>k;
    long long ans = 1;
    m = m - n;
    long long maxim, minim;
    maxim = max(n-k, k-1);
    minim = min(n-k, k-1);
    //cout<<ans<<' '<<sqrt(m)<<endl;
    if((minim+1)*(minim+1)>=m)  cout<<ans+(long long)sqrt(m);
    else
    {
        int x;
        ans += (minim+1);
        m -= (minim+1)*(minim+1);
        x = 2*minim + 2;
        while(x<=n && m>=x)
        {
            m-=x;
            x++;
            ans++;
        }
        if(x>n) ans += m/n;

        cout<<ans;
    }

    return 0;
}
