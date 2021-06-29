#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define exp .0000000001
ll  combi[300005];
vector< pair<ll,ll> > mv;
long long bigmod(long long B,long long P,long long MOD)
{
    long long R=1;
    while(P>0){
        if(P%2==1){
            R=(R*B)%MOD;
        }
        P/=2;
        B=(B*B)%MOD;
    }
    return R;
}
ll ncr(ll n, ll r ){

    ll a=combi[n];
    ll b= combi[r]*combi[n-r];
    b%=mod;
    b=bigmod(b,mod-2, mod);
    //cout<<"n : "<<n<<" r: "<<r<<" = "<< (a*b)%mod<<endl;
    return (a*b)%mod;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;

    combi[0]=1;
    combi[1]=1;
    for(ll i=2;i<=200005;i++){
        combi[i]=combi[i-1]*i;
        combi[i]%=mod;
    }
    for(int tc=1;tc<=T;tc++){
        ll n,m;
        cin>>n>>m;
        mv.clear();
        bool zero=true, nminus1=true;
        for(int i=0;i<m;i++){
            ll a, b;
            cin>>a>>b;
            pair<ll,ll> temp;
            temp.first=a;
            temp.second=b;
            mv.push_back(temp);
            if(a==0) zero=false;
            if(a==n) nminus1=false;
        }
        if(zero)mv.push_back(make_pair(0,1));
        if(nminus1)mv.push_back(make_pair(n,n));
        sort(mv.begin(),mv.end());
        vector<ll> ans;
        for(int i=0;i<mv.size();i++){
            //cout<<mv[i].first<<" --  "<<mv[i].second<<endl;
            if(i+1==mv.size()) break;

            pair<ll, ll > temp1, temp2;
            temp1=mv[i];
            temp2=mv[i+1];
            ll pos_dif=temp2.first-temp1.first;
            ll val_dif=temp2.second-temp1.second;
            ans.push_back(ncr(pos_dif+val_dif-1,val_dif));

        }
        ll num=1;
        for(int i=0;i<ans.size();i++){
            num*=ans[i];
            num%=mod;
        }
        for(int i=1;i<mv.size();i++){
            if(mv[i].second<mv[i-1].second){
                num=0;
                break;
            }
        }
        cout<<"Case "<<tc<<": "<<num<<"\n";
    }


}
