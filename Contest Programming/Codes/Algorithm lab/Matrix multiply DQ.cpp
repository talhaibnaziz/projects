#include <bits/stdc++.h>
using namespace std;
int n, a[10][10], b[10][10], c[10][10];
void rec(int ai, int aj, int bi, int bj, int n)
{
    //cout<<ai<<' '<<aj<<' '<<bi<<' '<<bj<<' '<<n<<endl;
    if(n==1)
    {
        c[ai][bj]+=a[ai][aj]*b[bi][bj];
        return;
    }
    int half=n/2;
    rec(ai, aj, bi, bj, half);
    rec(ai, aj+half, bi+half, bj, half);

    rec(ai, aj, bi, bj+half, half);
    rec(ai, aj+half, bi+half, bj+half, half);

    rec(ai+half, aj, bi, bj, half);
    rec(ai+half, aj+half, bi+half, bj, half);

    rec(ai+half, aj, bi, bj+half, half);
    rec(ai+half, aj+half, bi+half, bj+half, half);
}
int main()
{
    freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
            c[i][j]=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>b[i][j];
        }
    }
    rec(0, 0, 0, 0, n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<c[i][j]<<' ';
        }
        cout<<"\n";
    }

    return 0;
}

