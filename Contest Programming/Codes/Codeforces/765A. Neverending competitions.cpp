#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string home, flights[110];
    cin>>home;
    for(int i=0; i<n; i++)  cin>>flights[i];
    if(n%2==0)  printf("home");
    else    printf("contest");

    return 0;
}
