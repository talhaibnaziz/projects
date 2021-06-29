#include <bits/stdc++.h>
using namespace std;

bool prime[1006];
void seive()
{
    memset(prime, 1, sizeof prime);
    int val = sqrt(1000)+1;
    prime[0]=0;
    prime[1]=0;
    for(int i=2; i<val; i++)
    {
        if(!prime[i])   continue;
        //cout<<i<<endl;
        for(int j=i; i*j<1001; j++)
        {
            prime[i*j]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seive();
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int k;
        bool found = 0;
        cin>>k;
        for(int i=2; i<k; i++)
        {
            if(!prime[i])   continue;
            for(int j=i; j<k; j++)
            {
                if(!prime[j])   continue;
                int rem = k-i-j;
                if(prime[rem])
                {
                    cout<<i<<' '<<j<<' '<<rem<<'\n';
                    found = 1;
                    break;
                }
            }
            if(found)   break;
        }
        if(!found)  cout<<"0\n";
    }

    return 0;
}
