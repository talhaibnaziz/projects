#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int t, cases;
    while(cin>>cases)
    {
        t=0;
        string s; int k, ans;
        while(t++<cases)
        {
            cin>>s>>k;
            ans=0;
            int len = s.size();
            for(int i=0; i<(len-k+1); i++)
            {
                if(s[i]=='-')
                {
                    ans++;
                    for(int j=i; j<(i+k); j++)
                    {
                        if(s[j]=='-')   s[j]='+';
                        else    s[j]='-';
                    }
                    //cout<<s<<endl;
                }
            }
            bool possible = 1;
            for(int i=len-k; i<len; i++)
            {
                if(s[i]=='-')
                {
                    possible = 0;
                    break;
                }
            }
            cout<<"Case #"<<t<<": ";
            if(possible)    cout<<ans<<"\n";
            else    cout<<"IMPOSSIBLE\n";
        }
    }


    return 0;
}
