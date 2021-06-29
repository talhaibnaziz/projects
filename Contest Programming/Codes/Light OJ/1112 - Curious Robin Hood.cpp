#include <bits/stdc++.h>
using namespace std;
int ar[100005], tree[300015], ans;

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=ar[b];
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node]=tree[Left]+tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)  return 0;
    if(b>=i && e<=j)    return tree[node];
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    int p1=query(Left, b, mid, i, j);
    int p2=query(Right, mid+1, e, i, j);
    return p1+p2;
}
void addupdate(int node, int b, int e, int i, int addvalue)
{
    if(i>e || i<b)  return;
    if(b>=i && e<=i)
    {
        tree[node]+=addvalue;
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    addupdate(Left, b, mid, i, addvalue);
    addupdate(Right, mid+1, e, i, addvalue);
    tree[node]=tree[Left]+tree[Right];
}
void donateupdate(int node, int b, int e, int i)
{
    if(i>e || i<b)  return;
    if(b>=i && e<=i)
    {
        ans=tree[node];
        tree[node]=0;
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    donateupdate(Left, b, mid, i);
    donateupdate(Right, mid+1, e, i);
    tree[node]=tree[Left]+tree[Right];
}
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) scanf("%d", &ar[i]);
        init(1, 1, n);
        printf("Case %d:\n", t);
        for(int i=0; i<q; i++)
        {
            int choice;
            scanf("%d", &choice);
            if(choice==1)
            {
                int sackno;
                scanf("%d", &sackno);
                donateupdate(1, 1, n, sackno+1);
                printf("%d\n", ans);
            }
            else if(choice==2)
            {
                int sackno, amnt;
                scanf("%d %d", &sackno, &amnt);
                addupdate(1, 1, n, sackno+1, amnt);
            }
            else
            {
                int range1, range2;
                scanf("%d %d", &range1, &range2);
                printf("%d\n", query(1, 1, n, range1+1, range2+1));
            }
        }
    }

    return 0;
}
