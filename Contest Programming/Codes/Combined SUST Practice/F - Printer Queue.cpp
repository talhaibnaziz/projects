#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue <int> q;
    int cnt[10];
    int cases, t=0;
    int n, m, k;
    scanf("%d", &cases);
    while(t++<cases)
    {
        memset(cnt, 0, sizeof cnt);
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &k);
            q.push(k);
            cnt[k]++;
        }
        int ans = 0;
        int present;
        bool repeat;
        while(!q.empty())
        {
            present = q.front();
            repeat = 0;
            //cout<<present<<' '<<m<<endl;
            for(int i=present+1; i<10; i++)
            {
                if(cnt[i]!=0)
                {
                    q.pop();
                    q.push(present);
                    m--;
                    if(m==-1)   m=q.size()-1;
                    repeat = 1;
                    break;
                }
            }
            if(!repeat)
            {
                q.pop();
                ans++;
                m--;
                cnt[present]--;
                if(m==-1)   break;
            }
        }
        printf("%d\n", ans);
        while(!q.empty())   q.pop();
    }

    return 0;
}
