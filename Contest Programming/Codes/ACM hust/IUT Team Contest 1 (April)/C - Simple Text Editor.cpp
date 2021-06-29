#include <bits/stdc++.h>
using namespace std;

string app[1000006];
string del[2000006];
string c[1000006];

int main()
{
    ios_base::sync_with_stdio(false);
    int q, in, d;
    int cmd=0, appcnt=0, delcnt=0;
    string s, tmp, ans;
    char ch;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        cin>>in;
        if(in==1)
        {
            cin>>s;
            c[cmd]="append";
            cmd++;
            app[appcnt]=s;
            appcnt++;
            ans=ans+s;
        }
        else if(in==2)
        {
            cin>>d;
            int len = ans.size();
            for(int loop=0; loop<d; loop++)
            {
                ch=ans[len-1];
                len--;
                ans.pop_back();
                tmp.push_back(ch);
            }
            for(int loop=0; loop<d/2; loop++)
            {
                swap(tmp[loop], tmp[d-loop-1]);
            }
            del[delcnt]=tmp;
            delcnt++;
            tmp.clear();
            c[cmd]="delete";
            cmd++;
        }
        else if(in==3)
        {
            cin>>d;
            cout<<ans[d-1]<<"\n";
        }
        else
        {
            cmd--;
            if(c[cmd]=="delete")
            {
                delcnt--;
                ans=ans+del[delcnt];
            }
            else
            {
                appcnt--;
                d = app[appcnt].size();
                for(int loop=0; loop<d; loop++)
                {
                    ans.pop_back();
                }
            }
        }
    }

    return 0;
}
