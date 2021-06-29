#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        char player[10];
        scanf("%d %s", &n, &player);
        printf("Case %d: ", t);
        if(strcmp(player, "Alice")==0)
        {
            if(n%3==1)    printf("Bob\n");
            else   printf("Alice\n");
        }
        else
        {
            if(n%3==0)  printf("Alice\n");
            else    printf("Bob\n");
        }
    }

    return 0;
}
