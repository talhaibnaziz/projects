#include <bits/stdc++.h>
using namespace std;

int ar[100005], tree[300015];

void init(int node, int b, int e)
{
    if(b==e){
        tree[node]=ar[b];
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node]=min(tree[Left], tree[Right]);
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)  return 999999;
    if(b>=i && e<=j)    return tree[node];
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    int p1=query(Left, b, mid, i, j);
    int p2=query(Right, mid+1, e, i, j);
    return min(p1, p2);
}
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++)  scanf("%d", &ar[i]);
        init(1, 1, n);
        printf("Case %d:\n", t);
        for(int i=0; i<q; i++)
        {
            int I, J;
            scanf("%d %d", &I, &J);
            printf("%d\n", query(1, 1, n, I, J));
        }
    }

    return 0;
}
