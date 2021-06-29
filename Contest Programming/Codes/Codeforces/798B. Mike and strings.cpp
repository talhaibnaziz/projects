#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b)
{
    int len = a.size();
    for(int i=0; i<len; i++)
    {
        bool possible = 1;
        for(int j=0; j<len; j++)
        {
            if(a[j]!=b[(j+i)%len])
            {
                possible = 0;
                break;
            }
        }
        if(possible)    return 1;
    }
    return 0;
}
int steps(string a, string b, int d)
{
    int len = a.size();
    for(int i=0; i<len; i++)
    {
        bool possible = 1;
        for(int j=0; j<len; j++)
        {
            if(a[(j+d)%len]!=b[(j+i)%len])
            {
                possible = 0;
                break;
            }
        }
        if(possible)    return i;
    }
}

int main()
{
    int n, len;
    cin>>n;
    string arr[55];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    bool possible = 1;
    for(int i=1; i<n; i++)
    {
        if(!check(arr[i-1], arr[i]))
        {
            possible = 0;
            break;
        }
    }
    if(possible)
    {
        int len = arr[0].size();
        string ideal = arr[0];
        int ans = 99999999, sum;
        for(int i=0; i<len; i++)
        {
            sum = 0;
            for(int j=0; j<n; j++)
            {
                sum += steps(ideal, arr[j], i);
                //cout<<"for array: "<<j<<' '<<sum<<endl;
            }
            ans = min(ans, sum);
            //cout<<ans<<' '<<i<<endl;
        }
        printf("%d", ans);
    }
    else    printf("-1");

    return 0;
}
