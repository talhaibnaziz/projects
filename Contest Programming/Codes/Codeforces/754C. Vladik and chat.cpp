#include <bits/stdc++.h>
using namespace std;

map <string, bool> mp, tmpmp;
string names[110];
vector <string> ans[110];

bool valid(char ch)
{
    if((ch<='z' && ch>='a') || (ch<='Z' && ch>='A'))    return 1;
    return 0;
}

bool valid2(char ch)
{
    if((ch<='z' && ch>='a') || (ch<='Z' && ch>='A') || (ch<='9' && ch>='0'))    return 1;
    return 0;
}

int main()
{
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int n, m;
        string s, name;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            mp[s]=1;
            names[i]=s;
        }
        cin>>m;
        getchar();
        for(int i=0; i<m; i++)
        {
            getline(cin, s);
            bool unknown = 0;
            int len = s.length();
            for(int j=0; j<len; j++)
            {
                //cout<<j<<endl;
                if(s[j]==':')
                {
                    if(!(j==1 && s[0]=='?'))
                    {
                        //copy s[0]-s[j-1] -> ans[i];
                        name = s.substr(0, j);
                        ans[i].push_back(name);
                        break;
                    }
                    else unknown = 1;
                }
                if(unknown)
                {
                    if(valid(s[j]) && !valid(s[j-1]))
                    {
                        int loop = 0;
                        while((j+loop)<len && loop<11 && valid2(s[j+loop])) loop++;
                        //copy s[j]-s[j+loop-1] -> name;
                        name = s.substr(j, loop);
                        if(mp[name])    tmpmp[name]=1;
                        //cout<<"I AM HERE "<<name<<endl;
                    }
                }
            }
            if(unknown)
            {
                for(int j=0; j<m; j++)  if(!(tmpmp[names[j]]))  ans[i].push_back(names[j]);
            }
            tmpmp.clear();
        }
        mp.clear();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<ans[i].size(); j++)
            {
                cout<<ans[i][j]<<' ';
            }
            cout<<'\n';
            ans[i].clear();
        }
    }

    return 0;
}
