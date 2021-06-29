#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int arr[100005];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    int lft=1, rt=0;
    for(int i=0; i<(n-1); i++)
    {
        if(arr[i]!=arr[i+1])
        {
            lft=i+1;
            break;
        }
    }
    for(int i=n-1; i>0; i--)
    {
        if(arr[i]!=arr[i-1])
        {
            rt=i-1;
            break;
        }
    }
    if(lft>rt)  printf("0");
    else    printf("%d", rt-lft+1);

    return 0;
}
