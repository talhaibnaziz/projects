#include <bits/stdc++.h>
using namespace std;

int num[10];

bool rec(int sum)
{
    //cout<<sum<<endl;
    if(sum%3==0)
    {
        int tot=num[3]+num[6]+num[9];
        if(tot%2==0)    return 1;
        else    return 0;
    }
    for(int i=1; i<10; i++)
    {
        if(num[i]==0)   continue;
        sum=sum-i;
        if(sum%3==0)
        {
            num[i]--;
            //cout<<num[i]<<" "<<i<<endl;
            bool flag=rec(sum);
            num[i]++;
            if(flag)    return 0;
        }
        sum=sum+i;
    }

    return 1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases, t=0;
    scanf("%d", &cases);
    getchar();
    while(t++<cases)
    {
        string str;
        cin>>str;
        int sum=0;
        memset(num, 0, sizeof num);
        for(int i=0; i<str.size(); i++)
        {
            sum+=str[i]-'0';
            num[str[i]-'0']++;
        }
        if(rec(sum))   printf("Case %d: T\n", t);
        else    printf("Case %d: S\n", t);
    }

    return 0;
}
