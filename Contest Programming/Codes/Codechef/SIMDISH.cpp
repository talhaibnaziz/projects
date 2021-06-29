#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, cases;
    string a[5], b[5];
    cin>>cases;
    t=0;
    while(t++<cases)
    {
        for(int i=0; i<4; i++)  cin>>a[i];
        for(int i=0; i<4; i++)  cin>>b[i];
        int cnt = 0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(a[i]==b[j])
                {
                    cnt++;
                }
            }
        }
        if(cnt>1)   printf("similar\n");
        else    printf("dissimilar\n");
    }

    return 0;
}
