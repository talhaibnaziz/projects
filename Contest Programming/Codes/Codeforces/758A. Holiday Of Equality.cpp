#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[110];
    int sum=0;
    int m=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        m=max(m, arr[i]);
        sum+=arr[i];
    }
    printf("%d", m*n-sum);

    return 0;
}
