#include <bits/stdc++.h>
using namespace std;

#define mod 100000007
unsigned long long dp[2000005];

int main()
{
    vector <long long> powers;
    map <long long, bool> mp;
    long long cnt=0;
    for(long long i=2; i<=100000; i++)
    {
        for(long long j=i*i; j<=100000000000; j*=i)
        {
            if(mp.count(j)==0)
            {
                powers.push_back(j);
                mp[j]=1;
                cnt++;
            }
        }
    }
    sort(powers.begin(), powers.end());

    int t=0, cases;
    scanf("%d", &cases);
    freopen("out.txt", "w", stdout);
    while(t++<cases)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        int lo, mid, hi, lft=-1, rt=-1;
        lo=0; hi= cnt-1;
        while(hi>=lo)
        {
            mid = (hi+lo)/2;
            //cout<<hi<<' '<<lo<<' '<<mid<<' '<<powers[mid]<<endl;
            if((mid!=0 && a<powers[mid] && a>powers[mid-1]) || a==powers[mid])
            {
                lft = mid;
                break;
            }
            else if(a>powers[mid])   lo = mid+1;
            else    hi = mid-1;
        }
        //cout<<lft<<endl;
        lo=0; hi= cnt-1;
        while(hi>=lo)
        {
            mid = (hi+lo)/2;
            //cout<<hi<<' '<<lo<<' '<<mid<<' '<<powers[mid]<<endl;
            if((mid!=(cnt-1) && b>powers[mid] && b<powers[mid+1]) || b==powers[mid])
            {
                rt = mid;
                break;
            }
            else if(b>powers[mid])   lo = mid+1;
            else    hi = mid-1;
        }
        //cout<<rt<<endl;
        if(b>powers[cnt-1]) rt=cnt-1;
        if(a<powers[0]) lft=0;
        if(lft!=-1 && rt!=-1)   printf("Case %d: %llu\n", t, dp[rt-lft+1]);
        else printf("Case %d: 0\n", t);
    }

    return 0;
}
