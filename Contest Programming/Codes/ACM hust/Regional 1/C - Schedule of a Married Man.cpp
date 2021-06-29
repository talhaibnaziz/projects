#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int h11, h12, m11, m12;
        int h21, h22, m21, m22;
        scanf("%d:%d %d:%d", &h11, &m11, &h12, &m12);
        scanf("%d:%d %d:%d", &h21, &m21, &h22, &m22);
        int s1, s2, e1, e2;
        s1 = h11*60+m11;
        e1 = h12*60+m12;
        s2 = h21*60+m21;
        e2 = h22*60+m22;
        if(s1>e2 || s2>e1)  printf("Case %d: Hits Meeting\n", t);
        else    printf("Case %d: Mrs Meeting\n", t);
    }

    return 0;
}
