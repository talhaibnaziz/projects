#include <bits/stdc++.h>
using namespace std;

vector <int> stck;
vector <int> tmp;
vector <int> ans;
void flip(int n)
{
    for(int i=0; i<=n/2; i++)
    {
        swap(stck[i], stck[n-i]);
    }
}

int main()
{
    int s;
    while(scanf("%d", &s)==1)
    {
        for(int i=0; i<s; i++)
        {
            int in;
            cin>>in;
            stck.push_back(in);
            tmp.push_back(in);
        }
        sort(tmp.begin(), tmp.end());
        int rt=tmp.size()-1;
        while(rt>0)
        {
            if(tmp[rt]==stck[rt])
            {
                rt--;
                continue;
            }
            int pos=rt;
            while(tmp[rt]!=stck[pos])   pos--;
            flip(pos);
            flip(rt);
            if(pos!=0)  ans.push_back(s-pos);
            if(rt!=0)  ans.push_back(s-rt);
            //cout<<pos<<' '<<rt<<endl;
            rt--;
            //for(int i=0; i<stck.size(); i++)    cout<<stck[i]<<' ';
            //cout<<endl;
        }
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<' ';
        cout<<"0"<<endl;
        ans.clear();
        stck.clear();
        tmp.clear();
    }

    return 0;
}
