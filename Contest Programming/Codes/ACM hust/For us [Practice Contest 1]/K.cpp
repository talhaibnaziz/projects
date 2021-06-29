#include <bits/stdc++.h>
using namespace std;

map <int, int> mp;
vector <int> v;
bool flag[100005][2];
int wish[100005][2];

bool rec(int age, int akhn)
{
    if(age!=-1)
    {
        if(age==wish[akhn][0])
            return rec(akhn, wish[akhn][1]);
        else if(age==wish[akhn][1])
            return rec(akhn, wish[akhn][0]);
        else    return 0;
    }
    else
    {
        return (rec(akhn, wish[akhn][0]) || rec(akhn, wish[akhn][1]));
    }
}
int main()
{
    int k, w, a, b;
    cin>>k>>w;
    int cnt = 0;
    memset(wish, -1, sizeof wish);
    memset(flag, 0, sizeof flag);
    for(int i=1; i<=w; i++)
    {
        cin>>a>>b;
        if(mp[a]==0)
        {
            cnt ++;
            v.push_back(a);
            mp[a] = cnt;
        }
        if(wish[mp[a]][0]==-1) wish[mp[a]][0] = b;
        else    wish[mp[a]][1] = b;
    }
    bool ok=1;
    for(int i=0; i<cnt; i++)
    {
        if(flag[v[i]]==0)
            ok = rec(-1, v[i]);
    }

    return 0;
}
