#include <bits/stdc++.h>

using namespace std;

bool arr[100005];
int main()
{
    int n;
    memset(arr, 0, sizeof arr);
    scanf("%d", &n);
    int counter = n;
    for(int i=0; i<n; i++)
    {
        int in;
        scanf("%d", &in);
        arr[in]=1;
        if(arr[counter]!=1) printf("\n");
        while(arr[counter])
        {
            if(arr[counter-1])  printf("%d ", counter);
            else    printf("%d\n", counter);
            counter--;
        }
    }

    return 0;
}
