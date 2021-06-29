#include <bits/stdc++.h>
using namespace std;

int main()
{
    map <string, int> serial;
    int cases, t=0;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int k, cnt=0, ans=0;
        string ansstr;
        int freq[205]={0};
        scanf("%d", &k);
        getchar();
        for(int i=0; i<k; i++)
        {
            string str;
            cin>>str;
            if(!serial.count(str))
            {
                serial[str]=cnt;
                cnt++;
            }
            int idx=serial[str];
            freq[idx]++;
            if(ans<freq[idx])
            {
                ans=freq[idx];
                ansstr=str;
            }
        }
        cout<<"Case "<<t<<": "<<ansstr<<"\n";
        serial.clear();
    }

    return 0;
}
