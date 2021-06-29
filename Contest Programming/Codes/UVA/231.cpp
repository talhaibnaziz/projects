#include <bits/stdc++.h>
using namespace std;

int dp[5000][5000];
int n;
int ar[5000];

int rec(int i, int prev)
{
    if(i==n)    return 0;
    if(dp[i][prev]!=-1) return dp[i][prev];
    int choice1=0, choice2;
    choice2=rec(i+1, prev);
    if(ar[prev]>=ar[i])  choice1=max(rec(i+1, i)+1, choice1);

    return dp[i][prev]=max(choice1, choice2);
}

int main()
{
    //freopen("out.txt", "w", stdout);
    int t=0;
    ar[0]=999999999;
    while(++t)
    {
        scanf("%d", &ar[1]);
        if(ar[1]==-1)   break;
        if(t>1) printf("\n");
        int i;
        for(i=2; ; i++)
        {
            scanf("%d", &ar[i]);
            if(ar[i]==-1)   break;
        }
        n=i;
        memset(dp, -1, sizeof dp);
        printf("Test #%d:\n  maximum possible interceptions: %d\n", t, rec(0, 0)-1);
    }

    return 0;
}
