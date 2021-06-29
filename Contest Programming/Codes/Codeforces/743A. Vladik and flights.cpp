#include <bits/stdc++.h>
using namespace std;

bool line[100005];
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    a--; b--;
    getchar();
    for(int i=0; i<n; i++)
    {
        char ch;
        scanf("%c", &ch);
        if(ch=='0') line[i]=0;
        else    line[i]=1;
    }
    if(line[a]==line[b])    printf("0");
    else
    {
        int dis = 1000000;
        for(int i=a; i<n; i++)
        {
            if(line[a]!=line[i])
            {
                dis = min(dis, i-a);
                break;
            }
        }
        for(int i=a; i>=0; i--)
        {
            if(line[a]!=line[i])
            {
                dis = min(dis, a-i);
                break;
            }
        }
        for(int i=b; i<n; i++)
        {
            if(line[b]!=line[i])
            {
                dis = min(dis, i-b);
                break;
            }
        }
        for(int i=b; i>=0; i--)
        {
            if(line[b]!=line[i])
            {
                dis = min(dis, b-i);
                break;
            }
        }
        printf("%d", dis);
    }

    return 0;
}
