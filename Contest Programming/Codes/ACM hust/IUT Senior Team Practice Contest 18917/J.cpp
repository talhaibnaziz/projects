#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define exp .0000000001
vector<ll> mv;
int n,m;
string input[505];
struct node{
    char a;
    int time;
};
node ans[505][505];
int dirx[]={1,-1,0,0};
int diry[]={0,0,-1,1};
bool valid(int x, int y){
    if(x<0 || y<0 || x>=n || y>=m) return 0;
    if(input[x][y]=='#') return 0;
    else return 1;
}
void bfs(){
    queue<pair<int,int> > Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(input[i][j]>='a'  && input[i][j]<='z'){
                ans[i][j].a=input[i][j];
                ans[i][j].time=0;
                Q.push(make_pair(i,j));
            }
            else{
                ans[i][j].a=input[i][j];
                ans[i][j].time=505*505;
            }
        }
    }
    while(!Q.empty()){
        pair<int,int> temp=Q.front();
        Q.pop();
        if(ans[temp.first][temp.second].time==-1) continue;
        for(int i=0;i<4;i++){
            int x=temp.first+dirx[i];
            int y=temp.second+diry[i];

            int time=ans[temp.first][temp.second].time+1;
            if(valid(x,y)){
                if(ans[x][y].time<time) continue;
                else if(ans[x][y].time==time){
                    ans[x][y].a='*';
                    ans[x][y].time=-1;
                    continue;
                }
                else{
                    ans[x][y].a=ans[temp.first][temp.second].a;
                    ans[x][y].time=time;
                    Q.push(make_pair(x,y));
                }
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
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>input[i];
        bfs();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j].a;
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}
