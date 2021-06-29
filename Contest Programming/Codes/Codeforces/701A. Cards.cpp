#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ar[110], ser[110], n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>ar[i];
        ser[i]=i;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(ar[j]>ar[i])
            {
                swap(ar[j], ar[i]);
                swap(ser[j], ser[i]);
            }
        }
    }
    for(int i=1; i<=(n/2); i++)
    {
        cout<<ser[i]<<' '<<ser[n-i+1]<<endl;
    }

    return 0;
}
