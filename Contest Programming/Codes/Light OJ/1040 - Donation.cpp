#include <bits/stdc++.h>
using namespace std;

struct wire
{
    int u, v, w;
    bool operator<(const wire& rhs) const
    {
        return w < rhs.w;
    }
};

vector <wire> arr;
int par[60], n;

int findpar(int i)
{
    if(par[i]==i)   return i;
    else return par[i]=findpar(par[i]);
}

int mst()
{
    for(int i=0; i<n; i++)  par[i]=i;
    int cnt=0, cost=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(cnt==n)  break;
        wire w;
        w=arr[i];
        int u=findpar(w.u);
        int v=findpar(w.v);
        if(u!=v)
        {
            cost+=w.w;
            par[u]=v;
            cnt++;
        }
    }

    return cost;
}

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int tot=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int len;
                scanf("%d", &len);
                if(len!=0)
                {
                    tot+=len;
                    wire w;
                    w.u=i; w.v=j; w.w=len;
                    arr.push_back(w);
                }
            }
        }
        sort(arr.begin(), arr.end());
        bool flag=1;
        tot=tot-mst();
        int p=findpar(0);
        for(int i=1; i<n; i++)
        {
            if(findpar(i)!=p)
            {
                flag=0;
                break;
            }
        }
        if(flag)    printf("Case %d: %d\n", t, tot);
        else    printf("Case %d: -1\n", t);
        arr.clear();
    }

    return 0;
}
