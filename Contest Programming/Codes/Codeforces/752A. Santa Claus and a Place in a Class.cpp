#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int row, lane;
    row = k%(2*m);
    if(row==0)  row = 2*m;
    if(row%2==1)    row=(row+1)/2;
    else    row=row/2;

    if(k%(2*m)==0)  lane=k/(2*m);
    else    lane = k/(2*m)+1;

    if(k%2==0)  printf("%d %d R", lane, row);
    else    printf("%d %d L", lane, row);

    return 0;
}
