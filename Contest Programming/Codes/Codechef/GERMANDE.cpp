#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int o1, o2;
        scanf("%d %d", &o1, &o2);
        int n = o1*o2;
        arr[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i]+=arr[i-1];
        }
        bool ans = 0;
        for(int i=1; i<=o2; i++)
        {
            //cout<<"starts from: "<<i<<"\ndistrict wins:";
            int diswin, statewin = 0, j;
            for(j=i+o2-1; j<=n; j+=o2)
            {
                diswin = arr[j] - arr[j-o2];
                if(diswin>(o2/2))   statewin++;
                //cout<<' '<<diswin;
            }
            if(j<(n+o2))
            {
                diswin = arr[i-1]+arr[n]-arr[j-o2];
                if(diswin>(o2/2))   statewin++;
                //cout<<' '<<diswin;
            }
            //cout<<" State wins: "<<statewin<<endl;
            if(statewin>(o1/2))
            {
                ans = 1;
                break;
            }
        }
        if(ans) printf("1\n");
        else    printf("0\n");
    }

    return 0;
}
