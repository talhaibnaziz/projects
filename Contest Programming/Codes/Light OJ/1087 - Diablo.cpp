#include <bits/stdc++.h>
using namespace std;

#define mx 150010

int ar[mx];
struct info {
    int prop, sum;
} tree[1000000];
int n;
int pr=0;
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].sum = 1;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    pr = max(Left, Right);
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}
int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
int getindex(int node, int b, int e, int prev, int id, int carry = 0)
{
    if(b>n) return 0;
    int thissum = prev + tree[node].sum + carry * (e-b+1);
    //cout<<node<<' '<<b<<' '<<e<<' '<<prev<<' '<<thissum<<endl;
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    if(b==e && thissum==id) return b;
    else if(id>prev && id<=thissum)
    {
        int p1 = getindex(Left, b, mid, prev, id, carry + tree[node].prop);
        if(p1!=0)   return p1;
        int p2 = getindex(Right, mid + 1, e, prev + tree[Left].sum + (carry + tree[node].prop) * (mid-b+1), id, carry + tree[node].prop);
        return p2;
    }
    else return 0;
}
void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int q;
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) scanf("%d", &ar[i]);
        if(n==0)    getchar();
        getchar();
        init(1, 1, mx);
        /*for(int i=1; i<=n; i++) printf("%d ", ar[i]);
        printf("\n");*/
        printf("Case %d:\n", t);
        for(int i=0; i<q; i++)
        {
            char ch;
            int k;
            scanf("%c %d", &ch, &k);
            getchar();
            if(ch=='a')
            {
                n++;
                ar[n]=k;
                int prev = query(1, 1, mx, n, n);
                update(1, 1, mx, n, n, 1-prev);
            }
            else
            {
                //call army
                int idx = getindex(1, 1, mx, 0, k);
                /*printf("index: %d\n", idx);
                for(int i=1; i<=n; i++) printf("%d ", ar[i]);
                printf("\n");*/
                if(idx == 0)    printf("none\n");
                else
                {
                    printf("%d\n", ar[idx]);
                    int x = query(1, 1, mx, idx, idx);
                    update(1, 1, mx, idx, idx, -x);
                }
            }
        }
    }

    return 0;
}
/*

*/
