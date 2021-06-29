#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> ans[1000005];
map <pair<long long, long long>, bool> mp;
bool comp(const pair<long long, long long> &p1, const pair<long long, long long> &p2)
{
    if(p1.first == p2.first)   return p1.second<p2.second;
    return p1.first<p2.first;
}
long long arr[1000005];
int main()
{
    int n;
    long long l, r;
    scanf("%d %lld %lld", &n, &l, &r);
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr+n);
    int idx = 0;
    long long leftlim, rightlim;
    for(int i=1; i<n; i++)
    {
        rightlim = arr[i-1]+arr[i]-1;
        leftlim = arr[i]-arr[i-1]+1;
        if(rightlim<l || leftlim>r) continue;
        if(rightlim>r)  rightlim = r;
        if(leftlim<l)   leftlim = l;
        //cout<<leftlim<<' '<<rightlim<<endl;
        pair <long long, long long> p;
        p.first = leftlim; p.second = rightlim;
        if(mp.count(p)!=0)  continue;
        ans[idx] = p;
        idx++;
        mp[p] = 1;
    }

    /*for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            rightlim = arr[j]+arr[i]-1;
            leftlim = arr[i]-arr[j]+1;
            if(rightlim<l || leftlim>r) continue;
            if(rightlim>r)  rightlim = r;
            if(leftlim<l)   leftlim = l;
            //cout<<leftlim<<' '<<rightlim<<endl;
            pair <long long, long long> p;
            p.first = leftlim; p.second = rightlim;
            if(mp.count(p)!=0)  continue;
            ans[idx] = p;
            idx++;
            mp[p] = 1;
        }
    }*/
    //for(pair<long long, long long> p: ans)  cout<<p.first<<' '<<p.second<<endl;
    sort(ans, ans+idx, comp);
    //cout<<endl;
    //for(pair<long long, long long> p: ans)  cout<<p.first<<' '<<p.second<<endl;
    long long anscnt = ans[0].second - ans[0].first + 1, prevlft = ans[0].first, prevrt = ans[0].second;
    for(int i=1; i<idx; i++)
    {
        pair <long long, long long> p = ans[i];
        if(p.first>prevrt)  anscnt += p.second-p.first+1;
        else if(p.second<=prevrt)   continue;
        else    anscnt += p.second-prevrt;

        prevlft = p.first; prevrt = p.second;
    }
    cout<<anscnt;

    return 0;
}
/*
6 1 100
22 33 49 49 50 50
*/
