#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int ar[1005];
vector <vector<int>> ans;

int retgreedy(int i)
{
    if(i==2)
    {
        vector <int> s;
        s.push_back(ar[0]);
        s.push_back(ar[1]);
        ans.push_back(s);
        s.clear();
        s.push_back(ar[0]);
        ans.push_back(s);
        s.clear();
        s.push_back(ar[0]);
        s.push_back(ar[2]);
        ans.push_back(s);
        return ar[0]+ar[1]+ar[2];
    }
    if(i==1)
    {
        vector <int> s;
        s.push_back(ar[0]);
        s.push_back(ar[1]);
        ans.push_back(s);
        return ar[1];
    }
    if(i==0)
    {
        vector <int> s;
        s.push_back(ar[0]);
        ans.push_back(s);
        return ar[0];
    }
    else
    {
        if(ar[i]+2*ar[0]+ar[i-1]<ar[0]+2*ar[1]+ar[i])
        {
            vector <int> s;
            s.push_back(ar[0]);
            s.push_back(ar[i]);
            ans.push_back(s);
            s.clear();
            s.push_back(ar[0]);
            ans.push_back(s);
            s.clear();
            s.push_back(ar[0]);
            s.push_back(ar[i-1]);
            ans.push_back(s);
            s.clear();
            s.push_back(ar[0]);
            ans.push_back(s);
            return retgreedy(i-2)+ar[i]+2*ar[0]+ar[i-1];
        }
        vector <int> s;
        s.push_back(ar[0]);
        s.push_back(ar[1]);
        ans.push_back(s);
        s.clear();
        s.push_back(ar[0]);
        ans.push_back(s);
        s.clear();
        s.push_back(ar[i]);
        s.push_back(ar[i-1]);
        ans.push_back(s);
        s.clear();
        s.push_back(ar[1]);
        ans.push_back(s);
        return retgreedy(i-2)+ar[0]+2*ar[1]+ar[i];
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    sort(ar, ar+n);
    cout<<retgreedy(n-1)<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
