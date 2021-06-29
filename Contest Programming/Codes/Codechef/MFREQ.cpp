#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int sum[100005];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    sum[0]=1; arr[0]=-1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]==arr[i-1])    sum[i]=sum[i-1];
        else    sum[i]=1-sum[i-1];
    }
    for(int i=1; i<=n; i++) sum[i]+=sum[i-1];
    for(int i=0; i<m; i++)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        bool flag = 0;
        for(int j=l+k-1; j<=r; j++)
        {
            if((sum[j]-sum[j-k])==k || sum[j]==sum[j-k])
            {
                //cout<<j<<' '<<j-k<<endl;
                printf("%d\n", arr[j]);
                flag = 1;
                break;
            }
        }
        if(!flag)   printf("-1\n");
    }

    return 0;
}
