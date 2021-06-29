#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, d;
    scanf("%d %d", &m, &d);
    int days;
    if(m==2)    days = 28;
    else if(m==4 || m==6 || m==9 || m==11)  days = 30;
    else    days = 31;
    days = days - (7 - d + 1);
    if(days % 7 == 0)   printf("%d", days/7 + 1);
    else    printf("%d", days/7 + 2);

    return 0;
}
