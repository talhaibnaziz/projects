#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define exp .0000000001
struct node{
    ll num,val;

    bool operator < ( const node& p ) const
    {
        return val < p.val;
    }
};
ll int dix[50000];
vector< node > G[50000];

void dijakstra(){
    priority_queue<node> pq;
    node temp,temp2,temp3;
    temp.num=1;
    temp.val=9999999999;
    pq.push(temp);
    while(!pq.empty()){
        temp=pq.top();
        pq.pop();
        ll int u=temp.num;
        for(int i=0;i<G[u].size();i++){
            temp3=G[u][i];
            ll int v=temp3.num;
            temp2.num=v;
            temp2.val=min(temp.val,temp3.val);
            if(dix[v]<temp2.val){
                dix[v]=temp2.val;
                pq.push(temp2);
            }
        }

    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int n,e;
        cin>>n>>e;
        node temp;
        for(int i=0;i<=n;i++) G[i].clear();
        for(int i=0;i<e;i++){
            ll a,b,w;
            cin>>a>>b>>w;
            temp.num=b;
            temp.val=w;
            G[a].push_back(temp);
            temp.num=a;
            G[b].push_back(temp);
        }
        memset(dix, -1,sizeof dix);
        dijakstra();
        vector<ll int> mv;
        for(int i=2;i<=n;i++){
            //cout<<"i: "<<i<<"  val: "<<dix[i]<<endl;
            mv.push_back( dix[i]);
        }
        sort(mv.begin(),mv.end());
        int q;
        cin>>q;
        cout<<"Case "<<tc<<":\n";
        for(int i=0;i<q;i++){
            ll int c;
            cin>>c;
            ll int ans=mv.end()-lower_bound(mv.begin(),mv.end(),c);
            cout<<ans<<"\n";
        }
    }


}
