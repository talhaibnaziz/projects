#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define exp .0000000001
int vis[1001];
ll ara[1001][3];

ll dis(ll x1, ll y1, ll x2, ll y2){
    ll d=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

ll sq(ll a){
    return a*a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int n;
        memset(vis,0,sizeof vis);
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i][0]>>ara[i][1]>>ara[i][2];
        }
        queue<int> Q;
        Q.push(0);
        vis[0]=1;
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int i=0;i<n;i++){
                if(vis[i]!=0) continue;
                if(dis(ara[i][0],ara[i][1],ara[u][0],ara[u][1])==sq(ara[i][2]+ara[u][2])){
                    vis[i]=-vis[u];
                    Q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cout<<"not moving\n";
                continue;
            }
            ll d1=ara[0][2];
            ll d2=ara[i][2];
            ll g=__gcd(d1,d2);
            d1/=g;
            d2/=g;
            if(d2==1) cout<<d1<<" ";
            else cout<<d1<<"/"<<d2<<" ";
            if(vis[i]==1) cout<<"clockwise\n";
            else cout<<"counterclockwise\n";
        }
    }


}
