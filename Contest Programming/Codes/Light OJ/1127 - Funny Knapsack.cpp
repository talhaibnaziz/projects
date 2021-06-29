#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t = 0, cases;
    scanf("%lld", &cases);
    while(t++<cases)
    {
        long long n;
        long long k;
        scanf("%lld %lld", &n, &k);
        long long items[35];
        for(long long i=0; i<n; i++)  scanf("%lld", &items[i]);
        long long lft=n/2;
        long long rt=n-lft;
        long long comb1 = 1<<lft;
        long long comb2 = 1<<rt;
        //cout<<comb1<<' '<<comb2<<endl;
        vector <long long> set1, set2;
        for(long long j=0; j<comb1; j++)
        {
            long long sum = 0;
            for(long long i=0; i<lft; i++)
            {
                long long cmpare = 1<<i;
                if(cmpare & j) sum += items[i];
            }
            set1.push_back(sum);
        }
        for(long long j=0; j<comb2; j++)
        {
            long long sum = 0;
            for(long long i=0; i<rt; i++)
            {
                long long cmpare = 1<<i;
                if(cmpare & j) sum += items[i+lft];
            }
            set2.push_back(sum);
        }
        sort(set2.begin(), set2.end());
        /*cout<<"Left Set:\n";
        for(long long i=0; i<set1.size(); i++)    cout<<set1[i]<<endl;
        cout<<"Right Set:\n";
        for(long long i=0; i<set2.size(); i++)    cout<<set2[i]<<endl;*/
        long long s = set1.size();
        long long s2 = set2.size();
        long long ans = 0;
        long long cnt;
        for(long long i=0; i<s; i++)
        {
            long long lo = 0, hi = s2-1;
            long long mid;
            cnt = -1;
            while(hi>=lo)
            {
                mid = (lo+hi)/2;
                //printf("%lld %lld %lld\n", lo, hi, mid);
                if((set2[mid]+set1[i])>k)   hi = mid-1;
                else
                {
                    cnt = max(cnt, mid);
                    //cout<<cnt<<endl;
                    lo = mid+1;
                }
            }
            ans += cnt + 1;
        }
        printf("Case %lld: %lld\n", t, ans);
    }

    return 0;
}

