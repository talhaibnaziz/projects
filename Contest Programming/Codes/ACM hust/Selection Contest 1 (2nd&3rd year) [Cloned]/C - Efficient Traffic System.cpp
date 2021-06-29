#include <bits/stdc++.h>
using namespace std;

int par[20010];

int fpar(int n)
{
    if(par[n]==n)   return n;
    else return par[n]=fpar(par[n]);
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m, cnt=0;
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; i++) par[i]=i;
        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            int upar=fpar(u);
            int vpar=fpar(v);
            if(upar!=vpar)
            {
                cnt++;
                par[vpar]=upar;
            }
        }
        printf("Case %d: %d", t, (n-1)-cnt);
    }

    return 0;
}
