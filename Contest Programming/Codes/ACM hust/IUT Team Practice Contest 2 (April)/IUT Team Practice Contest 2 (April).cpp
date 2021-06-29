#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if(a%b==0)  return b;
    if(b%a==0)  return a;
    if(a>b) return GCD(b, a%b);
    else return GCD(a, b%a);
}
int x[100005];
int main()
{
    int t=0, cases, ans;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        long long ans2 = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &x[i]);
            if(i==0)    ans = x[i];
            else    ans = GCD(ans, x[i]);
            ans2 += (long long)x[i];
        }
        cout<<ans2<<' '<<ans<<'\n';
    }

    return 0;
}
