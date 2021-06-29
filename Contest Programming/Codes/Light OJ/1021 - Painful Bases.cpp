#include <bits/stdc++.h>
using namespace std;
int base, k, len;
string num, perm;
long long dp[20][66000];
long long chck()
{
    unsigned long long integer=0, mul;
    for(int i=len-1; i>=0; i--)
    {
        if(i==(len-1))  mul=1;
        else mul*=(unsigned long long)base;
        if(perm[i]>='0' && perm[i]<='9')    integer+=mul*((unsigned long long)perm[i]-'0');
        else    integer+=mul*((unsigned long long)perm[i]-'A'+10);
    }
    //cout<<integer<<' '<<mul<<endl;
    if(integer%(unsigned long long)k==0)    return 1;
    else    return 0;
}
long long rec(int pos, long long vis)
{
    if(pos==len)
    {
        //cout<<perm<<" (string)"<<endl;
        return dp[pos][vis]=chck();
    }
    //if(dp[pos][vis]!=-1)    return dp[pos][vis];
    long long ans=0;
    //cout<<pos<<' '<<perm<<endl;
    for(int i=0; i<len; i++)
    {
        if((vis & (1<<i))==0)
        {
            vis=vis | (1<<i);
            perm+=num[i];
            ans+=rec(pos+1, vis);
            vis=vis - (1<<i);
            perm.pop_back();
        }
    }
    return dp[pos][vis]=ans;
}
int main()
{
    //freopen("out.txt", "w", stdout);
    int cases, t=0;
    cin>>cases;
    while(t++<cases)
    {
        cin>>base>>k;
        cin>>num;
        memset(dp, -1, sizeof(dp));
        len=num.size();
        printf("Case %d: %lld\n", t, rec(0, 0));
    }

    return 0;
}
