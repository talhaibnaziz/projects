#include<bits/stdc++.h>
using namespace std;
int main()
{
   ///freopen("launch.txt","r",stdin);
  // freopen("launch.txt",w,stdout);
    string s;
    int i,flag=0,n,arr[300000];

    cin>>n;
    cin>>s;

        for(i=0;i<n;i++)
        {
            cin>>arr[i];

        }
    for(i=0;i<s.size()-1;i++)
    {
        if(s[i]=='R' && s[i+1]=='L')
        {
            flag=1;
            break;
        }
    }
    int minim=INFINITY;
    if(flag==0)cout<<"-1";
    else{

        for(i=0;i<n-1;i++)
        {
            if(s[i]=='R' && s[i+1]=='L')
            {
            if(((arr[i+1]-arr[i])/2)<minim)
            {
                minim=(arr[i+1]-arr[i])/2;
            }

            }
        }
        cout<<minim;

    }
    return 0;
}
