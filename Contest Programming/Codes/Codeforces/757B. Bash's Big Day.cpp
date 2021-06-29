#include <bits/stdc++.h>
using namespace std;

int arr[100005];
bool flag[100005];
int cnt[100005];

int main()
{
    memset(flag, 0, sizeof flag);
    memset(cnt, 0, sizeof cnt);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    sort(arr, arr+n);
    int tmp, ans=1;
    for(int i=2; i<=arr[n-1]; i++)
    {
        if(flag[i])   continue;
        //printf("%d\n", i);
        tmp=0;
        for(int j=2; i*j<=arr[n-1]; j++)
        {
            flag[i*j]=1;
            if(cnt[i*j]!=0)   tmp+=cnt[i*j];
        }
        if(cnt[i]) ans=max(ans, tmp+cnt[i]);
        else    ans=max(ans, tmp);
    }
    printf("%d", ans);

    return 0;
}
