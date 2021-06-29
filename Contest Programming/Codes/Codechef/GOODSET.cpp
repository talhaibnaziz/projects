#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    cin>>cases;
    int n;
    while(t++<cases)
    {
        scanf("%d", &n);
        for(int i=0, j=500; i<n; i++, j--)
        {
            if(i<(n-1))    printf("%d ", j);
            else    printf("%d\n", j);
        }
    }

    return 0;
}
