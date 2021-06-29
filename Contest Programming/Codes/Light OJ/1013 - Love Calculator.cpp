
#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int strl1, strl2; long long len;
long long dp1[110][110];
long long dp2[110][110][210];

long long rec(int i, int j)
{
    //cout<<i<<' '<<j<<endl;
    if(dp1[i][j]!=-1)    return  dp1[i][j];
    if(i==strl1 && j==strl2)    return dp1[i][j]=0;
    if(i==strl1)    return dp1[i][j]=rec(i, j+1)+1;
    if(j==strl2)    return dp1[i][j]=rec(i+1, j)+1;
    if(str1[i]==str2[j])  return dp1[i][j]=rec(i+1, j+1)+1;
    else
    {
        return dp1[i][j]=min(rec(i+1, j), rec(i, j+1))+1;
    }
}
long long rec1(int i, int j, int cnt)
{
    if(cnt>len) return 0;
    if(dp2[i][j][cnt]!=-1)    return  dp2[i][j][cnt];
    if(i==strl1 && j==strl2 && cnt==len)    return dp2[i][j][cnt]=1;
    if(i==strl1 && j==strl2)    return dp2[i][j][cnt]=0;
    if(i==strl1)    return dp2[i][j][cnt]=rec1(i, j+1, cnt+1);
    if(j==strl2)    return dp2[i][j][cnt]=rec1(i+1, j, cnt+1);
    if(str1[i]==str2[j])    return dp2[i][j][cnt]=rec1(i+1, j+1, cnt+1);
    return dp2[i][j][cnt]=rec1(i+1, j, cnt+1)+rec1(i, j+1, cnt+1);
}
int main()
{
    int t=0, cases;
    cin>>cases;
    while(t<cases)
    {
        cin>>str1>>str2;
        strl1=str1.size();
        strl2=str2.size();
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        len=rec(0, 0);
        printf("Case %d: %lld %lld\n", ++t, len, rec1(0, 0, 0));
    }
    return 0;
}
