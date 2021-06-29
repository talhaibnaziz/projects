#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    char ar[110];
    scanf("%d %d", &n, &k);
    getchar();
    scanf("%s", &ar);
    int len = strlen(ar);
    int pos;
    for(int i=0; i<len; i++)
    {
        if(ar[i]=='G')
        {
            pos = i;
            break;
        }
    }
    bool flag=0;
    for(int i=pos; i<len; i+=k)
    {
        if(ar[i]=='#')  break;
        if(ar[i]=='T')
        {
            flag=1;
            break;
        }
    }
    for(int i=pos; i>=0; i-=k)
    {
        if(ar[i]=='#')  break;
        if(ar[i]=='T')
        {
            flag=1;
            break;
        }
    }
    if(flag)    printf("YES");
    else    printf("NO");

    return 0;
}
