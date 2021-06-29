#include <bits/stdc++.h>
using namespace std;
string str1, str2, ans;
vector <string> arr;
int len;
int dp[110][110];

int findmin(int i, int j)
{
    if(i==str1.size() || j==str2.size())    return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    if(str1[i]==str2[j])    return dp[i][j]=findmin(i+1, j+1)+1;
    else return dp[i][j]=max(findmin(i+1, j),findmin(i, j+1));
}
void makestring(int i, int j, int s)
{
    if(s==len)  arr.push_back(ans);
    if(i==str1.size() || j==str2.size())    return;
    if(str1[i]==str2[j])
    {
        ans+=str1[i];
        makestring(i+1, j+1, s+1);
        ans.pop_back();
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])    makestring(i+1, j, s);
        else if(dp[i+1][j]<dp[i][j+1])  makestring(i, j+1, s);
        else
        {
            makestring(i+1, j, s);
            makestring(i, j+1, s);
        }
    }
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        cin>>str1;
        cin>>str2;
        memset(dp, -1, sizeof dp);
        len=findmin(0, 0);
        arr.clear();
        makestring(0, 0, 0);
        sort(arr.begin(), arr.end());
        if(len>0)   cout<<"Case "<<t<<": "<<arr[0]<<"\n";
        else cout<<"Case "<<t<<": :(\n";
    }

    return 0;
}
