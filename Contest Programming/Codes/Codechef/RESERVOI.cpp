#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        getchar();
        char res[1010][1010];
        for(int i=0; i<n; i++)
        {
            scanf("%s", &res[i]);
        }
        bool flag = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(res[i][j]=='B')
                {
                    if(i!=(n-1) && res[i+1][j]!='B')
                    {
                        flag = 0;
                        //cout<<i<<' '<<j<<' '<<"break"<<endl;
                        break;
                    }
                }
                else if(res[i][j]=='W')
                {
                    if(i==(n-1) || res[i+1][j]=='A')
                    {
                        flag = 0;
                        //cout<<i<<' '<<j<<' '<<"break"<<endl;
                        break;
                    }
                    else if(j==0 || res[i][j-1]=='A')
                    {
                        flag = 0;
                        //cout<<i<<' '<<j<<' '<<"break"<<endl;
                        break;
                    }
                    else if(j==(m-1) || res[i][j+1]=='A')
                    {
                        flag = 0;
                        //cout<<i<<' '<<j<<' '<<"break"<<endl;
                        break;
                    }
                }
            }
        }
        if(flag)    printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
