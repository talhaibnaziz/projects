#include <bits/stdc++.h>
using namespace std;

vector <int> bv;
vector <int> freq;
bool comp(int a, int b)
{
    return a>b;
}

int main()
{
    for(int i=1; i<7; i++)
    {
        for(int j=1; j<7; j++)
        {
            bv.push_back(i+j);
        }
    }
    sort(bv.begin(), bv.end());

    int t, l, cnt[95];
    string str;
    cin>>t;
    getchar();
    while(t--)
    {
        getline(cin, str);
        l = str.size();
        memset(cnt, 0, sizeof cnt);
        for(int i=0; i<l; i++)  cnt[str[i]]++;
        for(int i=48; i<93; i++)    if(cnt[i])  freq.push_back(cnt[i]);
        sort(freq.begin(), freq.end(), comp);
        //cout<<freq[0]<<endl;
        int len = freq.size();
        int ans=0;
        for(int i=0; i<len; i++)    ans+=freq[i]*bv[i];
        printf("%d\n", ans);
        freq.clear();
    }

    return 0;
}
