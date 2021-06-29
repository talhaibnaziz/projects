#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, digit, ans=0;
        scanf("%d %d", &n, &digit);
        ans++; int rem = digit;
        while(rem!=0)
        {
            while(rem<n)
            {
                rem = rem*10 + digit;
                ans++;
            }
            rem%=n;
        }
        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
