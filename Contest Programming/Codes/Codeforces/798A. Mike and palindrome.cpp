#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ans = 0;
    for(int i=0; i<s.length()/2; i++)
    {
        if(s[i]!=s[s.length()-i-1]) ans++;
    }
    if(ans == 1)    printf("YES");
    else if(ans == 0 && s.length()%2)   printf("YES");
    else    printf("NO");

    return 0;
}
