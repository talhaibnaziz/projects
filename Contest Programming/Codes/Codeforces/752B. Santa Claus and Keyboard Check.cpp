#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin>>s;
    cin>>t;
    string tmp;
    int len = s.size(), cnt=0;
    bool possible, flag[30]={0};
    pair <int, int> ans[30];
    for(int i=1; i<26; i++)
    {
        if(flag[i]) continue;
        for(int j=0; j<i; j++)
        {
            if(flag[j]) continue;
            possible = 1;
            char a='a'+i, b='a'+j;
            tmp = t;
            for(int l=0; l<len; l++)
            {
                bool changed = 0;
                if(tmp[l]==a)
                {
                    tmp[l]=b;
                    changed = 1;
                }
                else if(tmp[l]==b)
                {
                    tmp[l]=a;
                    changed = 1;
                }
                if(changed && tmp[l]!=s[l])
                {
                    possible = 0;
                    break;
                }
            }
            //cout<<a<<' '<<b<<endl;
            //if(a=='h' && b=='e')    cout<<tmp<<endl;
            if(possible && t!=tmp)
            {
                //cout<<a<<' '<<b<<' '<<tmp<<endl;
                t=tmp;
                flag[i]=1;
                flag[j]=1;
                pair <int, int> p;
                p.first=i;
                p.second=j;
                ans[cnt]=p;
                cnt++;
            }
        }
    }
    if(s==t)
    {
        printf("%d\n", cnt);
        for(int i=0; i<cnt; i++)
        {
            printf("%c %c\n", ans[i].first+'a', ans[i].second+'a');
        }
    }
    else    printf("-1");

    return 0;
}
