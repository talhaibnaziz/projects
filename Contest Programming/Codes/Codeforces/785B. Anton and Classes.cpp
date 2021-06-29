#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d", &n);
    int nfirst=1000000005, msecond=0, nsecond=0, mfirst=1000000005;
    for(int i=0; i<n; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        nfirst=min(nfirst, r);
        nsecond=max(nsecond, l);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        mfirst=min(mfirst, r);
        msecond=max(msecond, l);
    }
    int ans=max(msecond-nfirst, nsecond-mfirst);
    if(ans<0)   ans=0;
    printf("%d", ans);

    return 0;
}
