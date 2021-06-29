#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    getchar();
    int ar[105];
    memset(ar, 0, sizeof ar);
    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        ar[str.size()]++;
    }
    string s;
    cin>>s;
    int len=s.size();
    int bestcnt=0, worstcnt=0;
    for(int i=1; i<100; i++)
    {
        if(i<len)
        {
            bestcnt+=ar[i];
            worstcnt+=ar[i];
        }
        else break;
    }
    bestcnt++;
    worstcnt+=ar[len];
    //cout<<bestcnt<<' '<<worstcnt<<endl;
    int bestans=0, worstans=0;
    for(int i=1; i<=bestcnt; i++)
    {
        bestans++;
        if(i%k==0 && i!=bestcnt)  bestans+=5;
    }
    for(int i=1; i<=worstcnt; i++)
    {
        worstans++;
        if(i%k==0 && i!=worstcnt)  worstans+=5;
    }
    cout<<bestans<<' '<<worstans<<endl;

    return 0;
}
