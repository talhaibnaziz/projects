#include <bits/stdc++.h>
using namespace std;

map <long long, long long> mp;
int main()
{
    long long n;
    long long v[100010];
    scanf("%lld", &n);
    for(long long i=0; i<n; i++)
    {
        long long num;
        scanf("%lld", &num);
        v[i]=num;
        mp[num]++;
    }
    long long ans = 0, i = 0;
    while(n)
    {
        long long num = v[i];
        //cout<<num<<endl;
        ans += n - mp[num];
        mp[num]--;
        n--; i++;
    }

    cout<<ans;

    return 0;
}
