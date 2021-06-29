#include <bits/stdc++.h>
using namespace std;

int ingredients[100005];
vector <int> islands[100005];
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        memset(ingredients, 0, sizeof ingredients);
        int n, k, p, in;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &p);
            for(int j=0; j<p; j++)
            {
                scanf("%d", &in);
                islands[i].push_back(in);
                ingredients[in]++;
            }
        }
        bool possible = 1;
        for(int i=1; i<=k; i++)
        {
            if(ingredients[i]==0)
            {
                possible = 0;
                break;
            }
        }
        if(possible)
        {
            for(int i=0; i<n; i++)
            {
                p=islands[i].size();
                possible = 1;
                for(int j=0; j<p; j++)
                {
                    in = islands[i][j];
                    if(ingredients[in]<2)
                    {
                        possible = 0;
                        break;
                    }
                }
                if(possible)
                {
                    printf("some\n");
                    break;
                }
            }
            if(!possible)   printf("all\n");
        }
        else    printf("sad\n");
        for(int i=0; i<n; i++)  islands[i].clear();
    }

    return 0;
}
