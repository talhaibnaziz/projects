#include <bits/stdc++.h>
using namespace std;

long long arr[300005], sum[300005];

long long findmaxsum(int lft, int rt, int sz)
{
    //cout<<"inside:"<<' '<<lft<<' '<<rt<<' '<<sz<<endl;
    long long max_dif = 0;
    for(int j=lft; j<=(rt-sz+1); j++)
    {
        max_dif = max(max_dif, (sum[j+sz-1]-sum[j-1]));

        //cout<<j<<' '<<max_dif<<endl;
    }

    return max_dif;
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        sum[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &arr[i]);
            sum[i] = sum[i-1] + arr[i];
        }
        int lft = 1, rt = n, idx;
        long long ans = 0, max_dif;
        int sz[210];
        for(int i=0; i<m; i++)
        {
            scanf("%d", &sz[i]);
        }

        for(int i=0; i<m; i++)
        {
            max_dif = 0;
            long long tempdif;
            for(int j=lft; j<=(rt-sz[i]+1); j++)
            {
                if(i!=(m-1))    tempdif = (sum[j+sz[i]-1]-sum[j-1]) - findmaxsum(j+1, j+sz[i]-2, sz[i+1]);
                else    tempdif = (sum[j+sz[i]-1]-sum[j-1]);
                if(max_dif<tempdif)
                {
                    max_dif = tempdif;
                    idx = j;
                }
                //cout<<"outside: "<<' '<<j<<' '<<tempdif<<endl;
            }
            lft = idx+1; rt = idx+sz[i]-2;
            if(i%2==0) ans += sum[idx+sz[i]-1]-sum[idx-1];
            else    ans -= sum[idx+sz[i]-1]-sum[idx-1];
            //cout<<idx<<' '<<idx+sz[i]-1<<' '<<ans<<' '<<max_dif<<endl;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
