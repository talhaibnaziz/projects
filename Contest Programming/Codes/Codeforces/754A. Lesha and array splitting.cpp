#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[110];
    int sum[110];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(i>0) sum[i]=sum[i-1]+arr[i];
        else    sum[i]=arr[i];
    }
    if(sum[n-1]!=0) printf("YES\n1\n1 %d", n);
    else
    {
        bool yes = 0;
        for(int i=0; i<(n-1); i++)
        {
            if(sum[i]!=0 && (sum[n-1]-sum[i])!=0)
            {
                printf("YES\n2\n%d %d\n%d %d", 1, i+1, i+2, n);
                yes = 1;
                break;
            }
        }
        if(!yes)    printf("NO");
    }

    return 0;
}
