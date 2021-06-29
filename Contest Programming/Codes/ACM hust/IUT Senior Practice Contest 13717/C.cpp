#include<bits/stdc++.h>
#define pb push_back
using namespace std;


int main()
{
    int T;
    cin>>T;
    vector<int> v;
    while(T--)
    {
        int n;
        cin>>n;
        if(n%2==1)
        {
            v.pb(n/2);
            v.pb(n/2+1);
        }
        else
        {
            for(int i =3; ((i-1)*(i))/2<=n; i++)
            {
//              cout<<" "<<i<<"\n";
                if(i%2==0)
                {
                    int d = i/2;
                    if(n%d!=0)  continue;
                    if((n/d)%2==0)  continue;
                    else
                    {
                        for(int j=(n/d)-i; j; j++)
                        {
                            v.pb(j);
                        }
                        break;
                    }
                }
                else
                {
                    int half = i/2;
                    if(n%i==0)
                    {
                        if((n/i - half) <0)
                            break;
                        else
                        {
                            int inc;
                            inc = (n/i) -half;
                            for(int j=1 ; j<=i ; j++,inc++)
                            {
                                v.pb(inc);
                            }
                            break;
                        }
                    }
                }
            }
        }
        //cout<<v.size();

//        IMPOSSIBLE
//    10 = 1 + 2 + 3 + 4
// 24 = 7 + 8 + 9


        if(v.size()==0)
        {
            cout<<"IMPOSSIBLE\n";
        }
        else
        {
            cout<<n<<" =";
            for(int i=0; i<v.size(); i++)
            {
                if(v[i]==0) continue;
                cout<<" "<<v[i];
                if(i!=v.size()-1)
                {
                    cout<<" +";
                }
            }
            cout<<"\n";
        }
        v.clear();
    }
}
