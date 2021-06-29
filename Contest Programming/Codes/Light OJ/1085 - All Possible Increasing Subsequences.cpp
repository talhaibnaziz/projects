#include <bits/stdc++.h>
using namespace std;

#define mx 100001
#define mod 1000000007

struct info {
    long long prop, sum;
} tree[mx * 3];
struct thing {
    long long a;
    int ser;
    bool operator<(const thing& rhs) const
    {
        if(a==rhs.a)    return ser > rhs.ser;
        return a < rhs.a;
    }
} arr[mx];
void update(int node, int b, int e, int i, int j, long long x)
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

long long query(int node, int b, int e, int i, int j, long long carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return (tree[node].sum + carry * (e - b + 1)) % mod;

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    long long p1 = query(Left, b, mid, i, j, carry + tree[node].prop) % mod;
    long long p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop) % mod;

    return (p1 + p2) % mod;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &arr[i].a);
            arr[i].ser = i;
        }
        sort(arr+1,arr+n+1);
        memset(tree, 0, sizeof tree);
        for(int i=1; i<=n; i++)
        {
            if(arr[i].ser == 1) update(1, 1, n, 1, 1, 1);
            else
            {
                long long sum = query(1, 1, n, 1, arr[i].ser-1) % mod;
                update(1, 1, n, arr[i].ser, arr[i].ser, (sum+1) % mod);
                //printf("%lld %lld\n", arr[i].a, sum+1);
            }
        }
        printf("Case %d: %lld\n", t, query(1, 1, n, 1, n) % mod);
    }
    return 0;
}
