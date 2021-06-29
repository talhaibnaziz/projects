#include <bits/stdc++.h>
using namespace std;

struct mymap
{
    char s[12];
    double d;
    bool operator<(const mymap& rhs) const
    {
        int cmp = strcmp(s, rhs.s);
        if(cmp<0)   return 1;
        else    return 0;
    }
};
mymap arr[100005];

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, c;
        scanf("%d %d", &c, &n);
        char s[12];
        double d;
        for(int i=0; i<c; i++)
        {
            scanf("%s %lf", &s, &d);
            //cout<<s<<' '<<d<<endl;
            arr[i].d = d;
            strcpy(arr[i].s, s);
        }
        //cout<<"MIDWAY"<<endl;
        arr[c].d = 1.0;
        strcpy(arr[c].s,"JD");
        sort(arr, arr+c+1);
        //for(int i=0; i<=c; i++) cout<<arr[i].s<<endl;
        double ans = 0;
        int cmp;
        for(int i=0; i<n; i++)
        {
            scanf("%lf %s", &d, &s);
            int lo = 0, hi = c, mid;
            while(1)
            {
                mid = (hi+lo)/2;
                cmp = strcmp(arr[mid].s, s);
                //cout<<hi<<' '<<lo<<' '<<arr[mid].s<<endl;
                if(cmp==0)   break;
                else if(cmp>0)   hi = mid-1;
                else    lo = mid+1;
            }
            //cout<<arr[mid].s<<' '<<arr[mid].d<<endl;
            ans += arr[mid].d*d;
        }
        printf("%.6f\n", ans);
    }

    return 0;
}
