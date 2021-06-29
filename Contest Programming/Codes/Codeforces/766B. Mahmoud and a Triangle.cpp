#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    bool possible = 0;
    for(int i=0; i<(n-2); i++)
    {
        int a=arr[i], b=arr[i+1], c=arr[i+2];
        if((a+b)>c) possible = 1;
    }
    if(possible)    printf("YES");
    else    printf("NO");
    return 0;
}
