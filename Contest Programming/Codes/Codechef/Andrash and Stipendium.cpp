#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        int ar, sum;
        sum=0; bool flag=1;
        bool a; a=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &ar);
            sum+=ar;
            if(ar==2)    flag=0;
            if(ar==5)    a=1;
        }
        double gpa=(double)sum/(double)n;
        if(gpa<4.00)    flag=0;
        if(!a)  flag=0;
        if(flag)    printf("Yes\n");
        else    printf("No\n");
    }

    return 0;
}
