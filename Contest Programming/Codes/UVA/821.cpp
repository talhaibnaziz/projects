#include <bits/stdc++.h>
using namespace std;

int ar[105][105];
bool ase[105];
vector <int> nodes;

int main()
{
    int t=0;
    while(++t)
    {
        for(int i=1; i<=100; i++)
        {
            for(int j=1; j<=100; j++)
            {
                ar[i][j]=999999;
            }
        }
        memset(ase, 0, sizeof ase);
        int u, v;
        scanf("%d %d", &u, &v);
        if(u==0 && v==0)    break;
        ar[u][v]=1;
        nodes.push_back(u);
        nodes.push_back(v);
        ase[u]=1; ase[v]=1;
        while(1)
        {
            scanf("%d %d", &u, &v);
            if(u==0 && v==0)    break;
            ar[u][v]=1;
            if(!ase[u]) nodes.push_back(u);
            if(!ase[v]) nodes.push_back(v);
            ase[u]=1; ase[v]=1;
        }
        for(int k=0; k<nodes.size(); k++)
        {
            for(int i=0; i<nodes.size(); i++)
            {
                for(int j=0; j<nodes.size(); j++)
                {
                    int x=nodes[k], y=nodes[i], z=nodes[j];
                    ar[y][z]=min(ar[y][z], ar[y][x]+ar[x][z]);
                }
            }
        }
        int sum=0, cnt=0;
        for(int i=0; i<nodes.size(); i++)
        {
            for(int j=0; j<nodes.size(); j++)
            {
                if(i!=j)
                {
                    sum+=ar[nodes[i]][nodes[j]];
                    cnt++;
                }
            }
        }
        //cout<<sum<<' '<<cnt<<endl;
        printf("Case %d: average length between pages = %.3f clicks\n", t, (double)sum/(double)cnt);
        nodes.clear();
    }

    return 0;
}
