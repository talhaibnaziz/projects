#include <bits/stdc++.h>
using namespace std;

char arr[4][22];
int k, n;
int x, y;
bool fillup1()
{
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            int loop;
            for(loop=j; loop<(j+k); loop++)
                if(loop>=n || arr[i][loop]=='#')    break;

            if(loop==(j+k))
            {
                x=i; y=j;
                for(loop=j; loop<(j+k); loop++) arr[i][loop]='#';
                return 1;
            }
        }
    }
    return 0;
}
bool fillup2()
{
    for(int j=0; j<n; j++)
    {
        int loop;
        for(loop=0; loop<k; loop++)
            if(loop>=n || arr[loop][j]=='#')    break;

        if(loop==k)
        {
            x=0; y=j;
            for(loop=j; loop<(j+k); loop++) arr[loop][j]='#';
            return 1;
        }
    }
    return 0;
}

int rec()
{
    fillup1();
    rec();
    fillup2();
    rec();
}
int main()
{
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        scanf("%d %d", &k, &n);
        printf("%d\n", rec());
    }

    return 0;
}
