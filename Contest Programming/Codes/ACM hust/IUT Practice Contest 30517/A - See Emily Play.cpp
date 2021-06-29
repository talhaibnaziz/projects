#include <bits/stdc++.h>
using namespace std;

int d, s, a;
double dp[1000005];

double rec(int n)
{
    //cout<<n<<endl;
    if(n==1)    return (double)(a+s+d);
    if(dp[n]!=-1)   return dp[n];
    if(n%2==0)  return dp[n]=(double)d+rec(n/2);
    return  dp[n]=((double)s+rec(n-1))/2.0+((double)a+rec(n+1))/2.0;
}

int main()
{
    int t, n;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        scanf("%d %d %d %d", &n, &d, &s, &a);
        double initValue = -1;
        fill_n(dp, 1000001, initValue);
        //cout<<dp[0]<<' '<<dp[1]<<endl;
        printf("%.3f\n", rec(n));
    }

    return 0;
}
