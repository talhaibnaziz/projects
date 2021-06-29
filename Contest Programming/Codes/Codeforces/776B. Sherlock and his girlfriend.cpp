#include <bits/stdc++.h>
using namespace std;

bool flag[1000005];
int arr[1000005];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=2; i<=(n+1); i++)
    {
        flag[i]=1;
        arr[i]=2;
    }
    int val = sqrt(n+1)+1;
    int k, ans=0;
    for(int i=2; i<val; i++)
    {
        if(flag[i])
        {
            //cout<<i<<endl;
            k=1;
            arr[i]=1;
            k++;
            for(int j=2; i*j<=(n+1); j++)
            {
                flag[i*j]=0;
            }
        }
    }
    for(int i=2; i<=(n+1); i++)
    {
        if(flag[i]) arr[i]=1;
        else    arr[i]=2;
    }
    if(n<3) ans = 1;
    else    ans = 2;
    printf("%d\n", ans);
    for(int i=2; i<=(n+1); i++)
    {
        if(i<(n+1)) printf("%d ", arr[i]);
        else    printf("%d\n", arr[i]);
    }

    return 0;
}
