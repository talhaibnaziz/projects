#include <bits/stdc++.h>
using namespace std;

int dp[33000][10000];
int n;

int rec(int i, int prev)
{
    int choice1=0, choice2;
    choice2=rec(i+1, prev);
    if(prev>=ar[i])  choice1=max(rec(i+1, ar[i])+1, choice1);

    return max(choice1, choice2);
}
int ar[10000];
int main()
{
    int t=0;
    while(++t)
    {
        scanf("%d", &ar[0]);
        if(ar[0]==-1)   break;
        int i;
        for(i=1; ; i++)
        {
            scanf("%d", &ar[i]);
            if(ar[i]==-1)   break;
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n", t, rec())
    }

    return 0;
}
