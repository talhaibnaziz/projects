#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, ans = 0;
        bool due = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            bool fee;
            cin>>fee;
            if(!fee)
            {
                ans+=1000;
                due = 1;
            }
            if(due) ans+=100;
        }
        printf("%d\n", ans);
    }

    return 0;
}
