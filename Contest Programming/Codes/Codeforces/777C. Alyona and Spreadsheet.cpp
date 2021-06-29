#include <bits/stdc++.h>
using namespace std;

vector <long long> arr[100004];
vector <int> flags[100004];
map <pair<int, int>, bool > mp;

int main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int num;
            scanf("%lld", &num);
            arr[i].push_back(num);
            if(i>0) arr[i][j]+=arr[i-1][j];
        }
    }
    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<m; j++)
        {
            int lft, rt;
            if(i>0) lft = arr[i][j]-arr[i-1][j];
            else    lft = arr[i][j];
            rt = arr[i+1][j]-arr[i][j];
            if(lft<=rt)  flags[i].push_back(1);
            else    flags[i].push_back(0);
            if(i>0) flags[i][j]+=flags[i-1][j];
//            pair <int, int> p;
//            p.first = i;
//            p.second = flags[i][j];
//            mp[p]=1;
            //cout<<flags[i][j]<<"("<<lft<<' '<<rt<<")"<<' ';
        }
        //cout<<endl;
    }
    int k;
    scanf("%d", &k);
    for(int i=0; i<k; i++)
    {
        pair <int, int> p;
        int l, r;
        scanf("%d %d", &l, &r);
        if(l==r)    printf("Yes\n");
        else if(mp.count(p = make_pair(l-1,r-2))!=0)
        {
            //cout<<"repeat"<<endl;
            bool flag = mp[p];
            if(flag)    printf("Yes\n");
            else    printf("No\n");
        }
        else
        {
            l--; r--;
            r--;
            int dif = r-l+1;
            bool flag = 0;
            for(int j=0; j<m; j++)
            {
                if(l>0)
                {
                    if((flags[r][j]-flags[l-1][j])==dif)
                    {
                        flag=1;
                        break;
                    }
                }
                else
                {
                    if((flags[r][j])==dif)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            p = make_pair(l, r);
            //cout<<p.first<<' '<<p.second<<endl;
            mp[p]=flag;
            if(flag)    printf("Yes\n");
            else    printf("No\n");
        }
    }

    return 0;
}
