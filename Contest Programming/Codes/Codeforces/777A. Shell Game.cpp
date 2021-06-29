#include <bits/stdc++.h>
using namespace std;

int retans(int n, int x)
{
    if(x==1)
    {
        if(n%3==0)  return 1;
        if(n%6==1 || n%6==2)    return 0;
        return 2;
    }
    if(x==0)
    {
        if(n%3==1)  return 1;
        if(n%6==5 || n%6==0)    return 0;
        return 2;
    }
    if(n%3==2)  return 1;
    if(n%6==3 || n%6==4)    return 0;
    return 2;
}
int main()
{
    int n, x, ans;
    cin>>n>>x;
    if(retans(n,0)==x)  printf("0");
    else if(retans(n,1)==x)  printf("1");
    else    printf("2");

    return 0;
}
