#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, sum=0;
    int cnt[11]={0};
    string n;
    cin>>k>>n;
    int l=n.size();
    for(int i=0; i<l; i++)
    {
        cnt[n[i]-'0']++;
        sum += n[i]-'0';
    }
    int ans=0;
    int idx = 0;
    while(sum<k)
    {
        if(cnt[idx]==0)
        {
            idx++;
            continue;
        }
        cnt[idx]--;
        ans++;
        sum += 9-idx;
    }
    cout<<ans;

    return 0;
}
