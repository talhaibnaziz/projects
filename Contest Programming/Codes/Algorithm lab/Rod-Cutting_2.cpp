#include <bits/stdc++.h>
using namespace std;

int ar[]={0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int rod;

int rodcut(int len, int price)
{
    if(len>rod) return 0;
    cout<<len<<' ';
    if(len==rod)
    {
        printf("%d\n", price);
        return price;
    }
    int ans=0;
    for(int i=1; i<=(len+i) && i<=10; i++)
    {
        ans=max(ans, rodcut(len+i, price+ar[i]));
    }
    return ans;
}
int main()
{
    rod=10;
    cout<<rodcut(0, 0);

    return 0;
}
