#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t, cases;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin>>cases)
    {
        t=0;
        while(t++<cases)
        {
            long long n;
            cin>>n;
            int dig = log10(n);
            long long refr = 1;
            for(int i=0; i<dig; i++)
            {
                refr = refr*10 + 1;
            }
            long long ans=0;
            while(refr>0)
            {
                if(ans%10==9)  break;
                if((ans+refr)<=n)   ans+=refr;
                else    refr=refr/10;
                //cout<<refr<<' '<<ans<<endl;
            }
            cout<<"Case #"<<t<<": "<<ans<<"\n";
        }
    }


    return 0;
}
