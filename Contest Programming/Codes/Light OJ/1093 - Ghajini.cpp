#include <bits/stdc++.h>
using namespace std;

struct info
{
    int val;
    int max_val=-1;
    int min_val=99999999;
};
int ar[100005];
info tree[300015];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].val=ar[b];
        tree[node].max_val=ar[b];
        tree[node].min_val=ar[b];
        return;
    }
    int Left=node<<1;
    int Right=Left+1;
    int mid=(b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node].max_val=max(tree[Left].max_val, tree[Right].max_val);
    tree[node].min_val=min(tree[Left].min_val, tree[Right].min_val);
}
void update(int node, int b, int e, int i, int newvalue)
{
    if(i>e || i<b)  return;
    if(b>=i && e<=i)
    {
        tree[node].val=newvalue;
        tree[node].max_val=newvalue;
        tree[node].min_val=newvalue;
        return;
    }
    int Left=node<<1;
    int Right=Left+1;
    int mid=(b+e)/2;
    if(i>=b && i<=mid)  update(Left, b, mid, i, newvalue);
    else update(Right, mid+1, e, i, newvalue);
    tree[node].max_val=max(tree[Left].max_val, tree[Right].max_val);
    tree[node].min_val=min(tree[Left].min_val, tree[Right].min_val);
}
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, d;
        scanf("%d %d", &n, &d);
        for(int i=1; i<=n; i++) scanf("%d", &ar[i]);
        int ans=-1;
        init(1, 1, d);
        ans=max(ans, tree[1].max_val-tree[1].min_val);
        for(int i=1, j=d+1; j<=n; i++, j++)
        {
            if(i==(d+1))    i=1;
            update(1, 1, d, i, ar[j]);
            ans=max(ans, tree[1].max_val-tree[1].min_val);
        }
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
