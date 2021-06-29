#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int days=0, i=0;
    while(i<n)
    {
        //cout<<i<<' '<<arr[i]<<' '<<days<<endl;
        if(arr[i]<=2*k && arr[i]>k)
        {
            i++;
            days++;
        }
        else if(arr[i]>2*k)
        {
            days++;
            arr[i]-=2*k;
        }
        else
        {
            if(i==(n-1))
            {
                days++;
                i++;
            }
            else
            {
                if(arr[i+1]<=k)
                {
                    days++;
                    i+=2;
                }
                else
                {
                    days++;
                    i++;
                    arr[i]-=k;
                }
            }
        }
        //cout<<arr[i+1]<<endl;
    }
    printf("%d", days);

    return 0;
}
