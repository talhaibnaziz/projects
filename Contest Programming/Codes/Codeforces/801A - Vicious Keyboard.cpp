#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;

    int ss = s.size(), vk = 0, cnt;
    for(int i=0; i<ss-1; i++)
        if(s[i]=='V' && s[i+1]=='K')    vk++;
    for(int i=0; i<ss; i++)
    {
        if(s[i]=='V')   s[i] = 'K';
        else    s[i] = 'V';

        cnt = 0;
        for(int j=0; j<ss-1; j++)
            if(s[j]=='V' && s[j+1]=='K')    cnt++;
        vk = max(vk, cnt);

        if(s[i]=='V')   s[i] = 'K';
        else    s[i] = 'V';
    }

    cout<<vk;

    return 0;
}
