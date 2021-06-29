#include <bits/stdc++.h>
using namespace std;

vector <int> switches[45];
int ans[66000];
int n, m, limit;

void bfs()
{
    queue <int> q;
    q.push(0);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //cout<<"step: "<<ans[u]<<" bulbs: "<<u<<endl;
        for(int i=0; i<m; i++)
        {
            int tmp = u;
            for(int j=0; j<switches[i].size(); j++)
            {
                int cmp = 1<<switches[i][j];
                tmp = tmp ^ cmp;
            }
            //cout<<"next step: "<<tmp<<endl;
            if(ans[tmp]==0)
            {
                q.push(tmp);
                ans[tmp] = ans[u]+1;
            }
        }
    }

}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        scanf("%d %d", &n, &m);
        int k;
        for(int i=0; i<m; i++)
        {
            scanf("%d", &k);
            for(int j=0; j<k; j++)
            {
                int s;
                scanf("%d", &s);
                switches[i].push_back(s);
            }
        }
        //cout<<"limit: "<<limit<<endl;
        memset(ans, 0, sizeof ans);
        bfs();
        int q;
        scanf("%d", &q);
        getchar();
        printf("Case %d:\n", t);
        for(int i=0; i<q; i++)
        {
            limit = 1;
            char in[50];
            gets(in);
            int len = strlen(in);
            int num = 0;
            for(int j=len-1; j>=0; j--)
            {
                if(in[j]=='1')  num += limit;
                limit *= 2;
            }
            //cout<<"question: "<<num<<endl;
            //cout<<"answer: "<<ans[num]<<endl;
            if(num==0)  printf("0\n");
            else if(ans[num]==0)    printf("-1\n");
            else    printf("%d\n", ans[num]);
        }
        printf("\n");
        for(int i=0; i<m; i++)  switches[i].clear();
    }

    return 0;
}
