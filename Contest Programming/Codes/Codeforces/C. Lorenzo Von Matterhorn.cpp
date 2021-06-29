#include <bits/stdc++.h>
using namespace std;
long long id[1000];
int idx;
void fun(unsigned long long n)
{
    cout<<n<<endl;
    if(n>(500))
    {
        return;
    }
    id[idx++]=n;
    fun(2*n);
    fun(2*n+1);
    return;
}

int main()
{
    idx=0;
    fun(1);
    sort(id, id+idx);
    for(int i=0; i<idx; i++)    cout<<i<<' '<<id[i]<<endl;
    /*int q;
    cin>>q;

    int con;
    long long u, v, w;

    for(int i=0; i<q; i++)
    {
        cin>>con;
        if(con==1)
        {
            cin>>u>>v>>w;

        }
        else
        {
            cin>>u>>v;

        }
    }*/

    return 0;
}
