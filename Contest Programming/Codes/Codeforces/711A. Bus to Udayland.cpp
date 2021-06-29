#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool flag=0;
    cin>>n;
    getchar();
    char seats[1010][10];
    for(int i=0; i<n; i++)
    {
        cin>>seats[i];
    }
    for(int i=0; i<n; i++)
    {
        if(seats[i][0]=='O' && seats[i][1]=='O')
        {
            seats[i][0]='+';
            seats[i][1]='+';
            flag=1;
            break;
        }
        else if(seats[i][3]=='O' && seats[i][4]=='O')
        {
            seats[i][3]='+';
            seats[i][4]='+';
            flag=1;
            break;
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i=0; i<n; i++)
        {
            cout<<seats[i]<<endl;
        }
    }
    else printf("NO\n");

    return 0;
}
