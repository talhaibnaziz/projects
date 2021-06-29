#include <bits/stdc++.h>
using namespace std;

long long arra[100007], arrb[100007];
struct ab
{
    int pos;
    long long prod;
    bool operator<(const ab& rhs) const
    {
        return prod > rhs.prod;
    }
};
ab arr[100007];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)  scanf("%I64d", &arra[i]);
    for(int i=0; i<n; i++)  scanf("%I64d", &arrb[i]);
    for(int i=0; i<n; i++)
    {
        arr[i].pos = i+1;
        arr[i].prod = arra[i]+arrb[i];
    }
    sort(arr, arr + n);
    printf("%d\n", (n/2)+1);
    for(int i=0; i<((n/2)+1); i++)
    {
        if(i==(n/2))    printf("%d", arr[i].pos);
        else    printf("%d ", arr[i].pos);
    }

    return 0;
}
