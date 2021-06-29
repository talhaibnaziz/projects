#include <bits/stdc++.h>
using namespace std;

long long finddig(long long n)
{
    if(n==0)
        return 0;
    return (n%9==0)?9:(n%9);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    long long t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        cin>>a>>b;
        //cout<<"string: "<<a<<' '<<b<<endl;
        long long suma=0, sumb=0;
        long long sa = a.size();
        long long sb = b.size();
        for(long long i=0; i<sa; i++) suma += a[i]-'0';
        for(long long i=0; i<sb; i++) sumb += b[i]-'0';
        //cout<<"string to digit: "<<suma<<' '<<sumb<<endl;
        suma = finddig(suma);
        sumb = finddig(sumb);
        //cout<<"function: "<<suma<<' '<<sumb<<endl;
        long long ans=1;
        for(long long i=1; i<=sumb; i++)    ans = ans*suma;
        ans = finddig(ans);
        cout<<"Case "<<t<<": "<<ans<<"\n";
    }
    return 0;
}
