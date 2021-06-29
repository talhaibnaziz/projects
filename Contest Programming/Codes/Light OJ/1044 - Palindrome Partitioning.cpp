#include <bits/stdc++.h>
using namespace std;
char str[1010];
int strl;
int dp[1010][1010];
bool chck(int i, int j)
{
    int lim=i+(j-i)/2, loop, k;
    for(k=0, loop=i; loop<=lim; loop++, k++)
    {
        if(str[loop]!=str[j-k])  break;
    }
    if(loop==(lim+1))   return 1;
    return 0;
}
int rec(int i, int j)
{
    //cout<<i<<' '<<j<<endl;
    if(i>j) return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    int ans=9999;
    for(int loop=i; loop<=j; loop++)
    {
        if(chck(i, loop))   ans=min(ans, 1+rec(loop+1, j));
    }
    //cout<<i<<' '<<j<<' '<<ans<<endl;
    return dp[i][j]=ans;
}
int main()
{
    int cases, t=0;
    cin>>cases;
    while(t<cases)
    {
        cin>>str;
        strl=strlen(str);
        memset(dp, -1, sizeof(dp));
        cout<<"Case "<<++t<<": "<<rec(0, strl-1)<<"\n";
    }

    return 0;
}
