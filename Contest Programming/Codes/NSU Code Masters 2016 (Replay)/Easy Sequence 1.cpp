#include <bits/stdc++.h>
using namespace std;
long long ans[50];
long long F(int x)
{
    if(x==1) return 1;
    if(x%2==0)  return F(x/2)*F(x/2)+1;
    return F(x/2)*F(x/2+1)+2;
}

int main()
{
    for(int i=1; ; i++)
    {
        ans[i]=F(i);
        if(ans[i]>1000000000)
        {
            //cout<<ans[i]<<endl;
            break;
        }
    }
    //freopen("in.txt", "r",stdin);
    int cases, t=0;
    cin>>cases;
    while(t<cases)
    {
        long long x;
        cin>>x;
        for(int j=1; j<46; j++)
        {
            if(x==ans[j])
            {
                printf("Case %d: %d\n", ++t, j);
                break;
            }
        }
    }

    return 0;
}
