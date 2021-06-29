#include <bits/stdc++.h>
using namespace std;

bool holes[1000006];
bool ball[1000006];
int main()
{
    int n, m, k;
    memset(holes, 0, sizeof holes);
    int h, u, v, pos=1;
    scanf("%d %d %d", &n, &m, &k);
    memset(ball, 0, sizeof ball);
    ball[1]=1;
    for(int i=1; i<=m; i++)
    {
        scanf("%d", &h);
        holes[h]=1;
    }
    for(int i=0; i<k; i++)
    {
        scanf("%d %d", &u, &v);
        if((ball[u] && holes[u]) || (ball[v] && holes[v]))  continue;
        swap(ball[u], ball[v]);
    }
    for(int i=1; i<=n; i++) if(ball[i]) pos = i;
    printf("%d", pos);

    return 0;
}
