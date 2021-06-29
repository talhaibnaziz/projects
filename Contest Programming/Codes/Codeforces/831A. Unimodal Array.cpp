#include <bits/stdc++.h>
using namespace std;

int arr[110];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)  scanf("%d", &arr[i]);
    bool unimodal = 1;
    int mode = 0;
    for(int i=1; i<n; i++)
    {
        if(arr[i]>arr[i-1] && mode<2)   mode = 1;
        else if(arr[i]==arr[i-1] && mode<3) mode = 2;
        else if(arr[i]<arr[i-1])    mode = 3;
        else
        {
            unimodal = 0;
            break;
        }
    }
    if(unimodal)    cout<<"YES";
    else    cout<<"NO";

    return 0;
}
