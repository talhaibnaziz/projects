#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    bool ans = 1;
    int a[105];
    cin>>n>>k;
    int cnt2 = n*2;
    int cnt4 = n;
    int cnt1 = 0;
    for(int i=0; i<k; i++)  cin>>a[i];
    for(int i=0; i<k; i++)
    {
        while(a[i]>3 && cnt4>0)
        {
            a[i]-=4;
            cnt4--;
        }
    }
    for(int i=0; i<k; i++)
    {
        while(a[i]>0)
        {
            if(cnt4>0 && a[i]==3)
            {
                a[i]-=3;
                cnt4--;
            }
            else if(cnt4>0 && a[i]==2)
            {
                a[i]-=2;
                cnt1++;
                cnt4--;
            }
            else if(cnt4>0 && a[i]==1)
            {
                a[i]--;
                cnt2++;
                cnt4--;
            }
            else if(cnt2>0 && a[i]>1)
            {
                a[i]-=2;
                cnt2--;
            }
            else if(cnt1>0 && a[i]>0)
            {
                a[i]--;
                cnt1--;
            }
            else if(cnt2>0 && a[i]>0)
            {
                a[i]--;
                cnt2--;
            }
            else
            {
                ans = 0;
                break;
            }
        }
    }
    if(ans) cout<<"YES";
    else    cout<<"NO";

    return 0;
}
