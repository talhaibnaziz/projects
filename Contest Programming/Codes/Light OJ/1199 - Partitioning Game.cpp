#include <bits/stdc++.h>
using namespace std;

int grundy[10005];

int findgrundy(int n)
{
    if(n<3) return 0;
    //cout<<n<<endl;
    if(grundy[n]!=-1)   return grundy[n];
    int lim;
    if(n%2==0)  lim=n/2;
    else    lim=n/2+1;
    map <int, bool> x;
    for(int i=1; i<lim; i++)
    {
        int a=findgrundy(i);
        int b=findgrundy(n-1);
        x[a+b]=1;
    }
    int ret=0;
    while(x.count(ret))
    {
        ret++;
    }

    return grundy[n]=ret;
}

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    memset(grundy, -1, sizeof grundy);
    while(t++<cases)
    {
        int n, xorsum;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            int in;
            scanf("%d", &in);
            if(i==0)    xorsum = findgrundy(in);
            else    xorsum = xorsum ^ findgrundy(in);
        }
        if(xorsum==0)   printf("Case %d: Bob\n", t);
        else    printf("Case %d: Alice\n", t);
    }

    return 0;
}
