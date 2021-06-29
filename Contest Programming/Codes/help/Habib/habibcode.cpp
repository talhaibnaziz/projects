#include<bits/stdc++.h>
using namespace std;
struct player{
    int index;
    int x;
    int y;
};
bool operator<(player a,player b){
    if(a.x<b.x)
        return a.x>b.x;
    else if(a.x==b.x && a.y>b.y)
        return a.y<b.y;
    else
        return b.x>a.x;
}
int main(){
    int n,z;
    scanf("%d%d",&n,&z);
    int cnt=0;
    struct player pl[100005];
    struct player host;
    int participants[100005]={};
    host.index=1;
    host.x=0;
    host.y=0;
     priority_queue<player>p;

    for(int i=1;i<100005;i++){
        pl[i].index=i;
        pl[i].x=0;
        pl[i].y=0;
    }

    for(int i=0;i<z;i++){
        int g,b;
        scanf("%d%d",&g,&b);
        if(g==1){
            host.x++;
            host.y+=b;
            if(p.empty()){
                printf("%d\n",cnt+1);
                continue;
            }
            //host >> other
            while((host.x>p.top().x)||(host.x==p.top().x && host.y<p.top().y)){
                struct player temp;
                temp=p.top();
                participants[temp.index]--;
                p.pop();
                if(participants[temp.index]==0)
                    cnt--;
                if(p.empty())
                    break;
            }
            printf("%d\n",cnt+1);
        }
        else{
            //not gamer 1
                //other >> host
            if((pl[g].x>host.x)||(pl[g].x==host.x && pl[g].y<host.y)){
                pl[g].x++;
                pl[g].y+=b;
                p.push(pl[g]);
                participants[g]++;
                if(participants[g]==1)
                    cnt++;
            }
            else{
                pl[g].x++;
                pl[g].y+=b;
                //other >> host
                if((pl[g].x>host.x)||(pl[g].x==host.x && pl[g].y<host.y)){
                    p.push(pl[g]);
                    participants[g]++;
                    if(participants[g]==1)
                        cnt++;

                }
            }
             printf("%d\n",cnt+1);
        }
    }
}
