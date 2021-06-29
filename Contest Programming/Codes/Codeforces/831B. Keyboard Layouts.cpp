#include <bits/stdc++.h>
using namespace std;

map <char, char> mp;

int main()
{
    string a, b, input;
    cin>>a>>b>>input;
    for(int i=0; i<26; i++)
    {
        mp[a[i]] = b[i];
    }
    for(int i=0; i<input.size(); i++)
    {
        if(input[i]>='a' && input[i]<='z')   input[i] = mp[input[i]];
        else if(input[i]>='A' && input[i]<='Z')   input[i] = (mp[input[i]+32])-32;
    }
    cout<<input;

    return 0;
}
