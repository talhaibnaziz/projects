#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,binary=0,cnt=0,c=0,d,e;

    printf("enter the digital number:");
    scanf("%d",&a);
    int x = a;

    while(a!=0)
    {
        b=a%2;
        a=a/2;
        binary=binary+b;
        cnt=cnt+1;
        //cout<<binary<<' '<<b<<' '<<a<<endl;
        binary=binary*10;
    }
    binary=binary/10;
    cout<<"\n8421: ";
    //cout<<binary<<' '<<b<<' '<<a<<endl;
    while(c<cnt)
    {
        d=binary%10;
        e=binary/10;
        binary=e;
        printf("%d",d);
        c++;
    }
    a = x + 3;
    while(a!=0)
    {
        b=a%2;
        a=a/2;
        binary=binary+b;
        cnt=cnt+1;
        //cout<<binary<<' '<<b<<' '<<a<<endl;
        binary=binary*10;
    }
    binary=binary/10;
    cout<<"\nXS-3: ";
    //cout<<binary<<' '<<b<<' '<<a<<endl;
    while(c<cnt)
    {
        d=binary%10;
        e=binary/10;
        binary=e;
        printf("%d",d);
        c++;
    }

    return 0;
}
