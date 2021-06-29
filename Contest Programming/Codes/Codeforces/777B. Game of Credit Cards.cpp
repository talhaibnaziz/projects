#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    string sherlock, moriarty;
    cin>>sherlock>>moriarty;
    int shercnt[12]={0}, morcnt[12]={0};
    for(int i=0; i<n; i++)
    {
        shercnt[sherlock[i]-'0']++;
        morcnt[moriarty[i]-'0']++;
    }
    int moridx;
    int ans1 = 0;
    for(int i=0; i<10; i++)
    {
        moridx = i;
        while(shercnt[i]>0 && moridx<10)
        {
            if(morcnt[moridx]==0)
            {
                moridx++;
                continue;
            }
            shercnt[i]--;
            morcnt[moridx]--;
            ans1++;
        }
    }
    //cout<<ans1<<' '<<n<<endl;
    memset(shercnt, 0, sizeof shercnt);
    memset(morcnt, 0, sizeof morcnt);

    for(int i=0; i<n; i++)
    {
        shercnt[sherlock[i]-'0']++;
        morcnt[moriarty[i]-'0']++;
    }
    int ans2 = 0;
    for(int i=0; i<9; i++)
    {
        moridx = i+1;
        while(shercnt[i]>0 && moridx<10)
        {
            if(morcnt[moridx]==0)
            {
                moridx++;
                continue;
            }
            shercnt[i]--;
            morcnt[moridx]--;
            ans2++;
        }
    }
    cout<<n-ans1<<endl;
    cout<<ans2<<endl;

    return 0;
}
