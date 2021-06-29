#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int arr[100005], s, t, n;
    cin>>n>>s>>t;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    int c = s, cnt = 0;

    while(c!=t && cnt<=n)
    {
        c = arr[c];
        cnt++;
//        cout<<c<<' '<<cnt<<endl;
    }
    if(cnt > n) cout<<"-1";
    else    cout<<cnt;

    return 0;
}
