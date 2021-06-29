#include <bits/stdc++.h>
using namespace std;

vector <int> tree[30];
vector <string> ans;
char nodes[30];

void rec(vector <int> indegree, string str)
{
    bool flag=0;
    for(int i=0; i<indegree.size(); i++)
    {
        //cout<<indegree[i]<<' ';
        if(indegree[i]!=-1)
        {
            flag=1;
            break;
        }
    }
    //cout<<endl;
    if(flag==0)
    {
        ans.push_back(str);
        return;
    }
    for(int i=0; i<indegree.size(); i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=-1;
            str.push_back(nodes[i]);
            for(int j=0; j<tree[i].size(); j++) indegree[tree[i][j]]--;
            rec(indegree, str);
            for(int j=0; j<tree[i].size(); j++) indegree[tree[i][j]]++;
            str.pop_back();
            indegree[i]=0;
        }
    }
}

int main()
{
    //freopen("out.txt", "w", stdout);
    char in[200];
    int t=0;
    while(scanf("%[^\n]", &in)==1)
    {
        t++;
        if(t>1) cout<<"\n";
        int len=strlen(in);
        int cnt=0;
        map <char, int> mp;
        vector <int> indegree;
        for(int i=0; i<len; i++)
        {
            if(in[i]>='a' && in[i]<='z')
            {
                mp[in[i]]=cnt;
                nodes[cnt]=in[i];
                indegree.push_back(0);
                cnt++;
            }
        }
        getchar();
        scanf("%[^\n]", &in);
        getchar();
        len=strlen(in);
        int i=0;
        while(i<len)
        {
            tree[mp[in[i]]].push_back(mp[in[i+2]]);
            indegree[mp[in[i+2]]]++;
            i+=4;
        }
        rec(indegree, "\0");
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<"\n";
        ans.clear();
        indegree.clear();
        for(i=0; i<cnt; i++)    tree[i].clear();
    }

    return 0;
}
