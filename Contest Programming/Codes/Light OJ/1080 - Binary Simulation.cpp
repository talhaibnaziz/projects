#include <bits/stdc++.h>
using namespace std;

char str[100005];
struct info
{
    int prop;
    bool bit;
}tree[300015];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].bit=str[b]-'0';
        tree[node].prop=0;
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node].prop=0;
}

void update(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)  return;
    if(b>=i && e<=j)
    {
        tree[node].prop++;
        return;
    }
    int Left=node*2;
    int Right=Left+1;
    int mid=(b+e)/2;
    update(Left, b, mid, i, j);
    update(Right, mid+1, e, i, j);
}

bool query(int node, int b, int e, int i, int carry)
{
    //cout<<node<<' '<<carry<<endl;
    if(b>=i && e<=i)
    {
        if((carry+tree[node].prop)%2==0)  return tree[node].bit;
        else return (!(tree[node].bit));
    }
    int Left=node<<1;
    int Right=Left+1;
    int mid=(b+e)>>1;

    if(i>=b && i<=mid)   return query(Left, b, mid, i, carry+tree[node].prop);
    else return query(Right, mid+1, e, i, carry+tree[node].prop);
}

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%s", &str);
        n=strlen(str);
        for(int i=n; i>0; i--)  str[i]=str[i-1];
        str[n+1]='\0';
        init(1, 1, n);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", t);
        for(int i=0; i<q; i++)
        {
            char ch;
            int I, J;
            getchar();
            scanf("%c", &ch);
            if(ch=='I')
            {
                scanf("%d %d", &I, &J);
                update(1, 1, n, I, J);
            }
            else
            {
                scanf("%d", &I);
                cout<<query(1, 1, n, I, 0)<<"\n";
            }
        }
    }

    return 0;
}
