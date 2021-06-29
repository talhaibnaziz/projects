#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int arr[200005];
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<=n/2; i++)
    {
        if(i%2==1)  swap(arr[i], arr[n-i+1]);
    }
    for(int i=1; i<=n; i++) printf("%d ", arr[i]);

    return 0;
}
