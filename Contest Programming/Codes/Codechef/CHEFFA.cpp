#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=0, cases, n, arr[100];
    cin>>cases;
    while(t++<cases)
    {
        int cnt[8]={0}, idx=1;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int i;
        for(i=0; i<n; )
        {
            if(arr[i]==1 && idx==1) cnt[idx]++;
            else if(arr[i]==2 && idx<2)
            {
                idx++;
                continue;
            }
            else if(arr[i]==2 && idx==2) cnt[idx]++;
            else if(arr[i]==3 && idx<3)
            {
                idx++;
                continue;
            }
            else if(arr[i]==3 && idx==3) cnt[idx]++;
            else if(arr[i]==4 && idx<4)
            {
                idx++;
                continue;
            }
            else if(arr[i]==4 && idx==4) cnt[idx]++;
            else if(arr[i]==5 && idx<5)
            {
                idx++;
                continue;
            }
            else if(arr[i]==5 && idx==5) cnt[idx]++;
            else if(arr[i]==6 && idx<6)
            {
                idx++;
                continue;
            }
            else if(arr[i]==6 && idx==6) cnt[idx]++;
            else if(arr[i]==7 && idx<7)
            {
                idx++;
                continue;
            }
            else if(arr[i]==7 && idx==7) cnt[idx]++;
            else break;
            //cout<<arr[i]<<' '<<cnt[idx]<<' '<<idx<<endl;
            i++;
        }
        while(i<n)
        {
            if(arr[i]<idx)
            {
                idx--;
                continue;
            }
            else if(arr[i]==idx)    cnt[idx]--;
            else    break;
            //cout<<arr[i]<<' '<<cnt[idx]<<' '<<idx<<endl;
            i++;
        }
        int j;
        for(j=1; j<7; j++)  if(cnt[j]!=0)   break;
        if(i==n && j==7)    cout<<"yes\n";
        else    cout<<"no\n";
    }

    return 0;
}
