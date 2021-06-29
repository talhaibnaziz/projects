#include <bits/stdc++.h>
using namespace std;

double p[100010];
int main()
{
    int t=0, cases;
    p[1]=0;
    int cnt;
    for(int i=2; i<=100000; i++)
    {
        cnt=0; double sum=0;
        int val=sqrt(i);
        for(int j=2; j<=val; j++)
        {
            if(i%j==0)
            {
                cnt+=2;
                sum+=p[i/j];
                sum+=p[j];
                //cout<<i<<' '<<j<<endl;
            }
        }
        if(val*val==i)
        {
            cnt--;
            sum-=p[val];
        }
        if(cnt==0)  p[i]=2.00;
        else p[i]=((double)cnt+sum+2.00)/(double)(cnt+1);
        //cout<<i<<' '<<cnt<<' '<<p[i]<<endl;
    }
    cin>>cases;
    while(t++<cases)
    {
        int n;
        cin>>n;
        printf("Case %d: %f\n", t, p[n]);
    }

    return 0;
}
