#include <bits/stdc++.h>
using namespace std;
vector <int> ans;
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int L, P;
        scanf("%d %d", &P, &L);
        int eat=P-L;
        int val=sqrt(eat);
        for(int i=1; i<=val; i++)
        {
            if(eat%i==0)
            {
                int d=eat/i;
                //cout<<i<<' '<<d<<endl;
                if(i>L) ans.push_back(i);
                if(d>L && d!=i) ans.push_back(d);
            }
        }
        sort(ans.begin(), ans.end());
        int s=ans.size();
        printf("Case %d:", t);
        if(s==0)    printf(" impossible");
        else for(int i=0; i<s; i++) printf(" %d", ans[i]);
        printf("\n");
        ans.clear();
    }

    return 0;
}
