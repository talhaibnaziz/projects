#include <bits/stdc++.h>
using namespace std;

long long arr[100005];

int main()
{
    long long t=0, cases;
    cin>>cases;
    string s;
    while(t++<cases)
    {
        cin>>s;
        long long len=s.size();
        long long ans = 0, prev = 0;
        arr[len-1]=s[len-1]-'0';
        for(long long i=len-2; i>-1; i--)
        {
            if(s[i]=='1')
            {
                arr[i]=arr[i+1]+1;
                ans += len-i-arr[i];
                //cout<<ans<<' ';
                if(s[i+1]!='1')   prev++;
                ans += prev;
                //cout<<ans<<endl;
            }
            else    arr[i]=arr[i+1];
        }
        cout<<ans<<'\n';
    }

    return 0;
}
