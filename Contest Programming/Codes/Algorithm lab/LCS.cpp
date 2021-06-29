#include <bits/stdc++.h>
using namespace std;
string a, b;
int alen, blen;
int rec(int i, int j, string s)
{
    if(i==alen || j==blen)  return 0;
    if(a[i]==b[j])
    {
        s+=a[i];
        cout<<s<<endl;
        return 1+rec(i+1, j+1, s);
    }
    else return max(rec(i, j+1, s),rec(i+1, j, s));
}
int main()
{
    cin>>a;
    cin>>b;
    alen=a.size();
    blen=b.size();
    cout<<rec(0, 0, "\0");

    return 0;
}
