#include <bits/stdc++.h>
using namespace std;

struct city
{
    int ser;
    int pop;
    bool in;
    bool operator<(const city& rhs) const
    {
        return pop > rhs.pop;
    }
} arr[50010];
int pos[50010];
vector <int> edge[50010];
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i].pop);
            arr[i].ser = i+1;
            arr[i].in = 1;
        }
        sort(arr, arr+n);
        for(int i=0; i<n; i++)
        {
            pos[arr[i].ser] = i;
        }
        /*for(int i=1; i<=n; i++)
        {
            printf("node: %d   node pos: %d\n", i, pos[i]);
        }*/
        for(int i=0; i<(n-1); i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
        {
            arr[pos[i]].in = 0;
            //printf("after sort pos: %d    node id: %d\n", pos[i], i);
            for(int y : edge[i])
            {
                arr[pos[y]].in = 0;
                //printf("%d %d\n", y, arr[pos[y]].pop);
            }
            for(int j=0; j<n; j++)
            {
                //cout<<arr[i].pop<<' '<<arr[i].in<<endl;
                if(arr[j].in)
                {
                    if(i<n) printf("%d ", arr[j].ser);
                    else    printf("%d\n", arr[j].ser);
                    break;
                }
            }
            arr[pos[i]].in = 1;
            for(int y : edge[i])
            {
                arr[pos[y]].in = 1;
            }
        }
        for(int i=1; i<=n; i++) edge[i].clear();
    }

    return 0;
}

/*
1
6
5 10 15 20 25 30
1 3
2 3
3 4
4 5
4 6
*/
