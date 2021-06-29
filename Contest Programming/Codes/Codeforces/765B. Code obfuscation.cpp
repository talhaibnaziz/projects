#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len = s.size();
    bool flag[30]={0};
    bool possible = 1;
    for(int i=0; i<len; i++)
    {
        int pos = s[i]-'a';
        if(s[i]!='a' && flag[pos-1]!=1) possible = 0;
        flag[pos]=1;
    }
    if(possible)    printf("YES");
    else    printf("NO");

    return 0;
}
