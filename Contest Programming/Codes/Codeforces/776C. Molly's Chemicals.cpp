#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    long long arr[100005];
    map <long long, int> mp;
    arr[0]=0;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", &arr[i]);
        arr[i]+=arr[i-1];
        mp[arr[i]]++;
    }
    vector <long long> powers;
    for(long long p=k; p<=1e14; p*=k)
    {
        powers.push_back(p);
        powers.push_back(p*-1);
        cout<<p<<endl;
    }

    return 0;
}
