#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ar[100];
    int n;
    cin>>n;
    bool flag=0;
    for(int i=0; i<n; i++)  cin>>ar[i];
    for(int i=0; i<n-2; i++)
    {
        for(int j=i+2; j<n; j++)
        {
            int d=ar[i]+ar[j];
            for(int k=i+1; k<j; k++)
            {
                if(d%2==0 && (d/2)==ar[k])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    if(flag)    cout<<"YES";
    else cout<<"NO";

    return 0;
}
