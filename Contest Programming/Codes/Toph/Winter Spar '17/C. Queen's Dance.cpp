#include <bits/stdc++.h>
using namespace std;

map <pair<int, int>, bool> mp;
bool xis[1000005], yis[1000005];

int main()
{
    memset(xis, 0, sizeof xis);
    memset(yis, 0, sizeof yis);

    int x=0, y=0;
    while(x<=1000000)
    {
        if(xis[x] || yis[y])
        {
            x++;
            y++;
        }
        else
        {
            pair <int, int> p;
            p.first = x;
            p.second = y;
            mp[p]=1;
            swap(p.first, p.second);
            mp[p]=1;
            xis[x]=1; yis[y]=1;
            xis[y]=1; yis[x]=1;
            x+=2;
            y+=1;
        }
        //if(x<10)    cout<<x<<' '<<y<<endl;
    }
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        pair <int, int> p;
        p.first = x;
        p.second = y;
        if(mp.count(p)) printf("Bob\n");
        else    printf("Alice\n");
    }

    return 0;
}
