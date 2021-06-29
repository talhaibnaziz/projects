#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int lft[10];
int arr[1005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        memset(cnt, 0, sizeof cnt);
        memset(lft, 0, sizeof lft);
        for(int j=i; j<n; j++)
        {
            if(j==(i+1) && arr[j]!=arr[j-1])
            {
                lft[arr[j]]++;
                lft[arr[j-1]]++;
            }
            else if(j!=i && arr[j]!=arr[j-1])    lft[arr[j]]++;
            bool flag = 1;
            cnt[arr[j]]++;
            int maxval=0, minval=100000;
            for(int i=1; i<9; i++)
            {
                maxval=max(maxval, cnt[i]);
                minval=min(minval, cnt[i]);
            }
            if((maxval-minval)>1)   flag=0;
            for(int i=1; i<9; i++)
            {
                if(lft[i]>1)    flag=0;
            }
            if(flag)    ans = max(ans, j-i+1);
        }
    }

    return 0;
}
