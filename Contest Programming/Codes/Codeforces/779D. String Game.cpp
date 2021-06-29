#include <bits/stdc++.h>
using namespace std;
string t, p;
int l;
bool mark[200006];
bool removed[200006];

bool rem(int idx, int step)
{
    //cout<<"index: "<<idx<<endl;
    string s;
    s.push_back(t[idx]);
    for(int i=idx+1; i<l; i++)
    {
        //cout<<mark[i]<<' '<<removed[i]<<endl;
        if(mark[i] && !removed[i])
        {
            bool flag = rem(i, step+1);
            if(!flag)   return 0;
        }
        if(s[0]==t[i] && !removed[i])
        {
            if(step==0) removed[idx]=1;
            else    mark[idx]=0;
            mark[i]=1;
            //cout<<"return: "<<i<<endl;
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin>>t;
    cin>>p;
    l=t.size();
    memset(mark, 0, sizeof mark);
    memset(removed, 0, sizeof removed);
    int j=0;
    for(int i=0; i<l; i++)
    {
        if(t[i]==p[j])
        {
            mark[i]=1;
            j++;
            //cout<<i<<' ';
        }
    }
    //cout<<endl;
    int ans=-1;
    for(int i=0; i<l; i++)
    {
        int pos;
        scanf("%d", &pos);
        pos--;
        if(mark[pos] && ans==-1)
        {
            bool flag = rem(pos, 0);
            //cout<<flag<<endl;
            if(flag==0)
            {
                ans = i;
            }
            else    removed[pos]=1;
        }
        else    if(ans==-1) removed[pos]=1;
    }
    printf("%d", ans);

    return 0;
}
