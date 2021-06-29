#include <bits/stdc++.h>
using namespace std;

long long Ai[1005];
long long s;
bool change;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    long long t, tc=0;
    long long n, i, j, rem, in;
    long long cnt, sum;

    cin>>t;
    while(tc++<t)
    {
        cin>>n;
        cin>>s;
        change = 0;
        for(i=0; i<n; i++)
        {
            cin>>in;
            if(tc==1 || in!=Ai[i])    change=1;
            Ai[i] = in;
        }
        if(change)
        {
            cnt = 0;
            sort(Ai, Ai+n);
            for(i=0; i<n-2; i++)
            {
                if(Ai[i]>=((s/3)+1))    break;
                for(j=i+2; j<n; j++)
                {
                    sum = Ai[i]+Ai[j];
                    if(sum>s)   break;
                    rem = s - sum;
                    if(binary_search(Ai+i+1,Ai+j,rem))
                    {
                        cnt+=upper_bound(Ai+i+1,Ai+j,rem)-lower_bound(Ai+i+1,Ai+j,rem);
                    }
                    //cout<<"DEBUG:  "<<Ai[i]<<' '<<Ai[j]<<' '<<cnt<<endl;
                }
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}
