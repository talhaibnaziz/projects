#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin>>n;
    getchar();
    cin>>str;
    int ans=0, cnt=0;
    vector <int> v;
    for(int i=0; i<n; i++)
    {
        if(str[i]=='B' && i==(n-1))
        {
            cnt++;
            v.push_back(cnt);
            //cout<<cnt<<endl;
            ans++;
        }
        else if(str[i]=='B') cnt++;
        else if(str[i]=='W' && cnt!=0)
        {
            v.push_back(cnt);
            //cout<<cnt<<endl;
            cnt=0;
            ans++;
        }
    }
    cout<<ans<<endl;
    int len=v.size();
    for(int i=0; i<len; i++)
    {
        if(i>0)   cout<<' '<<v[i];
        else    cout<<v[i];
    }
    cout<<'\n';

    return 0;
}
