#include <bits/stdc++.h>
using namespace std;

vector <int> q;
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    bool vis[22][22];
    int fw[22];
    while(t++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int cnt=0, ans=0;
        int finished=0;
        memset(vis, 0, sizeof vis);
        memset(fw, 0, sizeof fw);
        for(int i=1; i<=n; i++)   q.push_back(i);
        while(1)
        {
            cnt++; ans++;
            if(cnt==(m+1))  cnt=1;
            if(fw[cnt]!=0)
            {
                q.push_back(fw[cnt]);
                fw[cnt]=0;
            }
            for(int i=0; i<q.size(); i++)
            {
                int person = q[i];
                if(!vis[person][cnt])
                {
                    fw[cnt]=person;
                    q.erase(q.begin()+i);
                    finished++;
                    vis[person][cnt]=1;
                    break;
                }
            }
            /*printf("Ferris Wheel:\n");
            for(int i=1; i<=m; i++)   printf("%d ", fw[i]);
            printf("\nQueue:\n");
            for(int i=0; i<q.size(); i++)   printf("%d ", q[i]);
            printf("\n");*/
            if(q.size()==n && finished==(n*m))  break;
            //if(ans>20)    break;
        }
        q.clear();
        printf("Case %d: %d\n", t, ans*5);
    }

    return 0;
}
