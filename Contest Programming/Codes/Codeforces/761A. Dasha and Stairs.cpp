#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    if(abs(a-b)>1 || (a==0 && b==0))  printf("NO");
    else    printf("YES");

    return 0;
}
