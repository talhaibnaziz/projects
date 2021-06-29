#include <bits/stdc++.h>
using namespace std;

int s[1004];
bool special[1004];

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &s[i]);
        }

        int cnt = 0;
        for(int i=1; i<n; i++)
        {
            if(s[i]==s[i-1])    cnt++;
        }
        if(cnt==(n-1))
        {
            printf("neutral\n");
            continue;
        }

        cnt = 0;
        for(int i=1; i<n; i++)
        {
            if(s[i]>=s[i-1])    cnt++;
        }
        if(cnt==(n-1))
        {
            printf("allGoodDays\n");
            continue;
        }

        cnt = 0;
        for(int i=1; i<n; i++)
        {
            if(s[i]<=s[i-1])    cnt++;
        }
        if(cnt==(n-1))
        {
            printf("allBadDays\n");
            continue;
        }

        cnt = 0;
        memset(special, 0, sizeof special);
        for(int i=1; i<(n-1); i++)
        {
            if(s[i-1]<s[i] && s[i]>s[i+1])
            {
                special[i]=1;
                cnt++;
            }
        }
        if(cnt>=2)
        {
            cnt = 0;
            int prev = 0;
            for(int i=1; i<(n-1); i++)
            {
                if(special[i] && prev!=0)
                {
                    cnt = max(cnt, i-prev-1);
                    prev = i;
                }
                else if(special[i]) prev = i;
            }
            printf("%d\n", cnt);
            continue;
        }
        printf("none\n");
    }

    return 0;
}
