#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d,e;
    while(cin>>a>>b>>c>>d>>e){
        if((a+b+c+d+e)==0) break;
        vector<int> mv1,mv2;
        mv1.push_back(a);
        mv1.push_back(b);
        mv1.push_back(c);
        mv2.push_back(d);
        mv2.push_back(e);
        sort(mv1.begin(),mv1.end());
        sort(mv2.begin(),mv2.end());

        int i=0;

    }
}
