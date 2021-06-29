#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int to,from,cost;
};
vector<node> mv;
vector< pair<int, int> > G1[10002],G2[10002];
int cost[10002],rcost[10002];
void reset()
{
    for(int i=0;i<10002;i++) cost[i]=98765432;
    for(int i=0;i<10002;i++) rcost[i]=98765432;
    mv.clear();
    for(int i=0;i<10002;i++) G1[i].clear();
    for(int i=0;i<10002;i++) G2[i].clear();
}
void dijakstra1(int s){
    cost[s]=0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<G1[u].size();i++){
            pair<int,int> p=G1[u][i];
            int v=p.first;
            int c=p.second;
            if(cost[v]>cost[u]+c){
                cost[v]=cost[u]+c;
                Q.push(v);
            }
        }
    }
}
void dijakstra2(int s){
    rcost[s]=0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        for(int i=0;i<G2[u].size();i++){
            pair<int,int> p=G2[u][i];
            int v=p.first;
            int c=p.second;
            if(rcost[v]>rcost[u]+c){
                rcost[v]=rcost[u]+c;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++){
        reset();
        int s, t,p;
        scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
        node temp;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&temp.from,&temp.to, &temp.cost);
            G1[temp.from].push_back(make_pair(temp.to,temp.cost));
            G2[temp.to].push_back(make_pair(temp.from,temp.cost));
            mv.push_back(temp);
        }
        dijakstra1(s);
        dijakstra2(t);
        int maxv=-1;
        for(int i=0;i<m;i++){
            int a=mv[i].from;
            int b=mv[i].to;
            int c=mv[i].cost;
            //cout<<a<<"  cost: "<<cost[a]<<endl;
            //cout<<b<<" rcost:  "<<rcost[b]<<endl;
            if(cost[a]+rcost[b]+c<=p){
                maxv=max(maxv,c);
            }
        }

        printf("Case %d: %d\n",tc,maxv);

    }
}
