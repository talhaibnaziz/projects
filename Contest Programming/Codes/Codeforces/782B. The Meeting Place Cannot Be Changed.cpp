#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double x[60005], v[60005];
    scanf("%d", &n);
    double lft=1000000001, rt=-1, mid1, mid2;
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &x[i]);
        lft = min(lft, x[i]);
        rt = max(rt, x[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%lf", &v[i]);
    }
    double ans = 1000000001;
    for(int i=0; i<100; i++)
    {
        mid1 = lft+((rt-lft)/3.00);
        mid2 = lft+(2*(rt-lft)/3.00);
        double t1=-1, t2=-1;
        for(int i=0; i<n; i++)
        {
            t1=max(t1,abs(mid1-x[i])/v[i]);
            t2=max(t2,abs(mid2-x[i])/v[i]);
        }
        //cout<<mid1<<' '<<mid2<<' '<<t1<<' '<<t2<<endl;
        ans = (t1+t1)/2.0;
        if(t1<t2)   rt=mid2;
        else    lft=mid1;
    }
    printf("%.7lf", ans);

    return 0;
}
