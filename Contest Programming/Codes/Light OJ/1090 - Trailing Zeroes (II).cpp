#include <bits/stdc++.h>
using namespace std;
int fact2[1000004], fact5[1000004], num2[1000004], num5[1000004];
int trail2(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n/2;
        n/=2;
    }
    return sum;
}
int trail5(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n/5;
        n/=5;
    }
    return sum;
}

int count2(int n)
{
    int sum=0;
    while(n%2==0)
    {
        sum++;
        n/=2;
    }

    return sum;
}

int count5(int n)
{
    int sum=0;
    while(n%5==0)
    {
        sum++;
        n/=5;
    }

    return sum;
}
int main()
{
    int m=0;
    for(int i=1; i<=1000000; i++)   fact5[i]=trail5(i);
    for(int i=1; i<=1000000; i++)
    {
        fact2[i]=trail2(i);
        m=max(m, fact2[i]);
    }
    for(int i=1; i<=1000000; i++)   num2[i]=count2(i);
    for(int i=1; i<=1000000; i++)   num5[i]=count5(i);
    int t=0, cases;
    //cout<<m<<endl;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, r, p, q;
        scanf("%d %d %d %d", &n, &r, &p, &q);
        int total2, total5;
        total2=fact2[n]-fact2[r]-fact2[n-r]+(q*num2[p]);
        total5=fact5[n]-fact5[r]-fact5[n-r]+(q*num5[p]);
        printf("Case %d: %d\n", t, min(total2, total5));
    }

    return 0;
}
