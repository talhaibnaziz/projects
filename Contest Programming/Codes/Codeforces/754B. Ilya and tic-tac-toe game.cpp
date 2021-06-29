#include <bits/stdc++.h>
using namespace std;

string ans[4];
string field[5];
int main()
{
    bool flag = 0;
    ans[0]=".xx";
    ans[1]="x.x";
    ans[2]="xx.";
    for(int i=0; i<4; i++)  cin>>field[i];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int ii=0; ii<3; ii++)
            {
                if(field[i][j]==ans[ii][0] && (j+1)<4 && field[i][j+1]==ans[ii][1] && (j+2)<4 && field[i][j+2]==ans[ii][2])   flag = 1;
                if(field[i][j]==ans[ii][0] && (i+1)<4 && field[i+1][j]==ans[ii][1] && (i+2)<4 && field[i+2][j]==ans[ii][2])   flag = 1;
                if(field[i][j]==ans[ii][0] && (i+1)<4 && (j+1)<4 && field[i+1][j+1]==ans[ii][1] && (i+2)<4 && (j+2)<4 && field[i+2][j+2]==ans[ii][2])   flag = 1;
                if(field[i][j]==ans[ii][0] && (i+1)<4 && (j-1)<4 && field[i+1][j-1]==ans[ii][1] && (i+2)<4 && (j-2)<4 && field[i+2][j-2]==ans[ii][2])   flag = 1;
            }
        }
    }
    if(flag) printf("YES");
    else    printf("NO");

    return 0;
}
