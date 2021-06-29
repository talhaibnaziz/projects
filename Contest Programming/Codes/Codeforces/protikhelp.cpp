#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1<<28
int n,m,t;
struct node{
    int next;
    int cost;
};
vector<node> G[5005];
int val[5005],par[5005];
void func(int u, int num, int cost, int parent)
{
    if(cost>t) return ;
    if(val[u]>=num) return ;
    val[u]=num;
    par[u]=parent;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].next;
        int c=G[u][i].cost;
        func(v,num+1,cost+c,u);
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>t;
    node temp;
    for(int i=0;i<m;i++){
        int a;
        cin>>a>>temp.next>>temp.cost;
        G[a].push_back(temp);
    }
    func(1,1,0,0);
    cout<<val[n]<<"\n";
    vector<int> mv;
    while(n!=0){
        mv.push_back(n);
        //cout<<"n: "<<n<<"  par: "<<par[n]<<endl;
        n=par[n];
    }
    for(int i=mv.size()-1;i>=0;i--) cout<<mv[i]<<" ";
}
