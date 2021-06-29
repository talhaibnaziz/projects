#include <bits/stdc++.h>
using namespace std;

struct nodes{
    int task;
    int days;
};
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cases, t=0;
    scanf("%d", &cases);
    getchar();
    getchar();
    vector <int> tree[30];
    int indegree[30];
    int days[30], prev[30];
    while(t++<cases)
    {
        memset(indegree, -1, sizeof indegree);
        char in[50];
        while(gets(in))
        {
            int len=strlen(in);
            //cout<<len<<endl;
            if(len==0)  break;
            indegree[in[0]-'A']=0;
            int num=0, lim=len;
            for(int i=2; i<len; i++)
            {
                if(in[i]<='9' && in[i]>='0')
                {
                    num*=10;
                    num+=in[i]-'0';
                }
                else
                {
                    lim=i;
                    break;
                }
            }
            if(len>lim)
            {
                for(int i=lim+1; i<len; i++)
                {
                    tree[in[i]-'A'].push_back(in[0]-'A');
                    indegree[in[0]-'A']++;
                }
            }
            days[in[0]-'A']=num;
            //cout<<in[0]<<' '<<num<<endl;
        }
        queue <nodes> q;
        for(int i=0; i<26; i++)
        {
            if(indegree[i]==0)
            {
                nodes n;
                n.task=i;
                n.days=days[i];
                q.push(n);
            }
        }
        int ans=0;
        memset(prev, 0, sizeof(prev));
        while(!q.empty())
        {
            nodes u=q.front();
            q.pop();
            ans=max(ans, u.days);
            //cout<<u.task<<' '<<u.days<<endl;
            for(int i=0; i<tree[u.task].size(); i++)
            {
                indegree[tree[u.task][i]]--;
                prev[tree[u.task][i]]=max(prev[tree[u.task][i]], u.days+days[tree[u.task][i]]);
                if(indegree[tree[u.task][i]]==0)
                {
                    nodes v;
                    v.task=tree[u.task][i];
                    v.days=prev[v.task];
                    //cout<<u.days<<' '<<days[v.task]<<endl;
                    q.push(v);
                }
            }
        }
        printf("%d\n", ans);
        if(t!=cases)    printf("\n");
        for(int i=0; i<26; i++) tree[i].clear();
    }

    return 0;
}
