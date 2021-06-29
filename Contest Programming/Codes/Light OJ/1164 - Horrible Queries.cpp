#include <bits/stdc++.h>
using namespace std;

struct info
{
    long long sum;
    long long prop;
}tree[300015];

void update(long long node, long long b, long long e, long long i, long long j, long long x)
{
    if(i>e || j<b)  return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    long long Left=node<<1;
    long long Right=Left+1;
    long long mid=(b+e)/2;
    update(Left, b, mid, i, j, x);
    update(Right, mid+1, e, i, j, x);
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
}

long long query(long long node, long long b, long long e, long long i, long long j, long long carry=0)
{
    if(i>e || j<b)  return 0;
    if(b>=i && e<=j)    return tree[node].sum+carry*(e-b+1);

    long long Left=node<<1;
    long long Right=Left+1;
    long long mid=(b+e)/2;

    long long p1=query(Left, b, mid, i, j, carry+tree[node].prop);
    long long p2=query(Right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}
int main()
{
    long long cases, t=0;
    scanf("%lld", &cases);
    while(t++<cases)
    {
        long long n, q;
        scanf("%lld %lld", &n, &q);
        for(long long i=1; i<=3*n; i++)
        {
            tree[i].sum=0;
            tree[i].prop=0;
        }
        printf("Case %lld:\n", t);
        for(long long i=0; i<q; i++)
        {
            long long choice;
            scanf("%lld", &choice);
            if(choice==0)
            {
                long long x, y, v;
                scanf("%lld %lld %lld", &x, &y, &v);
                update(1, 1, n, x+1, y+1, v);
            }
            else
            {
                long long x, y;
                scanf("%lld %lld", &x, &y);
                printf("%lld\n", query(1, 1, n, x+1, y+1));
            }
        }
    }

    return 0;
}
