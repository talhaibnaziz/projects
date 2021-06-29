#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s[100]={1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}, f[100]={4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    for(int i=0; i<10; i++)
    {
        for(int j=i+1; j<11; j++)
        {
            if(f[i]>f[j])
            {
                swap(f[i], f[j]);
                swap(s[i], s[j]);
            }
        }
    }
    int idx=1, ans=1, time=f[0];
    while(idx<11)
    {
        if(time<=s[idx])
        {
            ans++;
            time=f[idx];
        }
        idx++;
    }
    cout<<ans<<endl;

    return 0;
}
