#include <bits/stdc++.h>
using namespace std;

map <long long, bool> mp;

int main()
{
    long long b1, q, l, m;
    int ans=0;
    cin>>b1>>q>>l>>m;
    for(int i=0; i<m; i++)
    {
        long long a;
        scanf("%I64d", &a);
        mp[a]=1;
    }
    if(b1==0)
    {
        if(mp[0])   printf("0");
        else    printf("inf");
    }
    else if(q==0)
    {
        if(b1<=l && b1>=-l)
        {
            if(mp[0] && mp[b1]) printf("0");
            else if(mp[0])  printf("1");
            else    printf("inf");
        }
        else
        {
            if(mp[0])   printf("0");
            else    printf("inf");
        }
    }
    else if(q==1)
    {
        if(mp[b1] || (b1>l || b1<-l))  printf("0");
        else    printf("inf");
    }
    else if(q==-1)
    {
        if(mp[b1] && mp[-1*b1]) printf("0");
        else if(mp[b1])
        {
            if(b1<=l && b1>=-l) printf("inf");
            else    printf("0");
        }
        else if(mp[-1*b1])
        {
            if(b1<=l && b1>=-l) printf("inf");
            else    printf("0");
        }
        else
        {
            if(b1<=l && b1>=-l) printf("inf");
            else    printf("0");
        }
    }
    else
    {
        long long b=b1;
        while(b<=l && b>=-l)
        {
            if(mp[b]==0)    ans++;
            b*=q;
            //cout<<b<<endl;
        }
        printf("%d", ans);
    }

    return 0;
}
