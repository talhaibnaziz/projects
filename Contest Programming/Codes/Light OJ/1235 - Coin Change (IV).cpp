#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int coin[22];
        for(int i=0; i<n; i++)  scanf("%d", &coin[i]);
        int lft=n/2;
        int rt=n-lft;
        int comb1 = 1<<lft;
        int comb2 = 1<<rt;
        //cout<<comb1<<' '<<comb2<<endl;
        vector <int> set1, set2;
        for(int j=0; j<comb1; j++)
        {
            int cnt = 0;
            for(int i=0; i<lft; i++)
            {
                int cmpare = 1<<i;
                if(cmpare & j) cnt++;
            }
            int state = 1<<cnt;
            for(int i=0; i<state; i++)
            {
                int pos = 1;
                int sum = 0;
                for(int ii=0; ii<lft; ii++)
                {
                    int cmpare = 1<<ii;
                    if(cmpare & j)
                    {
                        if(pos & i) sum += 2*coin[ii];
                        else    sum += coin[ii];
                        pos = pos << 1;
                    }
                }
                set1.push_back(sum);
            }
        }
        for(int j=0; j<comb2; j++)
        {
            int cnt = 0;
            for(int i=0; i<rt; i++)
            {
                int cmpare = 1<<i;
                if(cmpare & j) cnt++;
            }
            int state = 1<<cnt;
            for(int i=0; i<state; i++)
            {
                int pos = 1;
                int sum =0;
                for(int ii=0; ii<rt; ii++)
                {
                    int cmpare = 1<<ii;
                    if(cmpare & j)
                    {
                        if(pos & i) sum += 2*coin[lft+ii];
                        else    sum += coin[lft+ii];
                        pos = pos << 1;
                    }
                }
                set2.push_back(sum);
            }
        }
        sort(set2.begin(), set2.end());
        /*cout<<"Left Set:\n";
        for(int i=0; i<set1.size(); i++)    cout<<set1[i]<<endl;
        cout<<"Right Set:\n";
        for(int i=0; i<set2.size(); i++)    cout<<set2[i]<<endl;*/
        int s = set1.size();
        int s2 = set2.size();
        bool flag = 0;
        for(int i=0; i<s; i++)
        {
            int lo = 0, hi = s2-1;
            int mid;
            while(hi>=lo)
            {
                mid = (lo+hi)/2;
                //printf("%d %d\n", set1[i], set2[mid]);
                if((set2[mid]+set1[i])>k)   hi = mid-1;
                else if((set2[mid]+set1[i])<k)  lo = mid+1;
                else
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)    break;
        }
        if(flag)    printf("Case %d: Yes\n", t);
        else    printf("Case %d: No\n", t);
    }

    return 0;
}
