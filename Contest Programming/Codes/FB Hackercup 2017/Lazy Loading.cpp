#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        int cnt[55];
        memset(cnt, 0, sizeof cnt);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int w;
            scanf("%d", &w);
            if(w>=50)   ans++;
            else    cnt[w]++;
        }
        int left = 49, rt = 1;
        while(left>0 && rt<50)
        {
            while(cnt[left]>0)
            {
                while(cnt[rt]>0)
                {

                }
            }
        }
    }

    return 0;
}
