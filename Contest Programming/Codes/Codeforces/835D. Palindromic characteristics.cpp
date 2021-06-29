#include <bits/stdc++.h>
using namespace std;

string str;
int dp[5005][5005];
int rec(int i, int j)
{
    if(i==j)    return 1;
    int half = (j-i+1)/2;
    int a = rec(i, i+half-1);
    int b = rec(j-half+1, j);
    if(a==b )
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    int n=str.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            rec(i, j);
        }
    }

    return 0;
}
