#include <bits/stdc++.h>
using namespace std;

int main()
{
    string as, bs;
    cin>>as;
    cin>>bs;
    if(as==bs)  printf("-1");
    else    printf("%d", max(as.size(),bs.size()));

    return 0;
}
