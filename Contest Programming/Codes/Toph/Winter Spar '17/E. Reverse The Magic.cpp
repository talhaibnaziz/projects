#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first == p2.first)   return p1.second<p2.second;
    return p1.first<p2.first;
}
vector <pair<int, int> > subarr;
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            pair <int, int> p;
            p.first = u;
            p.second = v;
            subarr.push_back(p);
        }
        sort(subarr.begin(), subarr.end(), comp);
        //for(pair <int, int> p: subarr)  cout<<p.first<<' '<<p.second<<endl;
        stack <pair<int, int> > stck;
        bool possible = 1;
        pair <int, int> stckval, vecval;
        for(int i=0; i<subarr.size(); i++)
        {
            if(subarr[i].first==0 && subarr[i].second!=(n-1)) {possible=0; break;}
            if(stck.empty())    stck.push(subarr[i]);
            else
            {
                stckval = stck.top();
                vecval = subarr[i];
                if(stckval.first==vecval.first && stckval.second==vecval.second)    continue;
                else if(vecval.first>stckval.first && vecval.second<=stckval.second)    stck.push(subarr[i]);
                else if(vecval.first>stckval.second)    {stck.pop(); i--;}
                else    {possible=0; break;}
            }
            //cout<<"stack: "<<stckval.first<<' '<<stckval.second<<" vector: "<<vecval.first<<' '<<vecval.second<<endl;
        }
        if(possible)    printf("Yes\n");
        else    printf("No\n");
        subarr.clear();
    }

    return 0;
}
