#include <bits/stdc++.h>
using namespace std;
long long divisor;
long long func(string s)
{
    long long ret = 0, mul = 1;
    for(int i=s.size()-1; i>=0; i--)
    {
        ret += mul * (long long)(s[i]-'0');
        mul*=10;
    }

    return ret;
}
int rec(string s, int dig)
{
    int ans = 11;
    long long n = func(s);
    if(n!=0 && n%divisor==0)    return dig;
    else if(n==0 && s.size()==1)    return dig;
    for(int i=0; i<s.size(); i++)
    {
        string t=s;
        t.erase(t.begin()+i);
        ans=min(ans,rec(t, dig+1));
    }
    return ans;
}

int main()
{
    long long n, k;
    string s;
    cin>>s>>k;
    n=func(s);
    //cout<<n<<endl;
    divisor = 1;
    for(long long i=1; i<=k; i++)
    {
        divisor*=10;
    }
    long long rem = n%divisor;
    int ans = rec(s, 0);
    if(ans==11) ans = 0;

    printf("%d", ans);

    return 0;
}
