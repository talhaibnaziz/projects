#include <bits/stdc++.h>
using namespace std;

struct item
{
    int a;
    int b;
    int dif;
    bool operator<(const item& rhs) const
    {
        return dif < rhs.dif;
    }
}arr[200005];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i].a);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i].b);
        arr[i].dif=arr[i].a-arr[i].b;
    }
    sort(arr, arr+n);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        //cout<<arr[i].a<<' '<<arr[i].b<<' '<<arr[i].dif<<' '<<ans<<endl;
        if(i<k) ans+=arr[i].a;
        else if(arr[i].dif<0)   ans+=arr[i].a;
        else    ans+=arr[i].b;
    }
    printf("%d", ans);

    return 0;
}
