#include <bits/stdc++.h>
using namespace std;

long long modify;

vector <vector<long long> > matrix_mul(vector <vector<long long> > a, vector <vector<long long> > b)
{
    vector <vector<long long> > c;
    long long c11,c12,c21,c22;
    c11 = (a[0][0]*b[0][0]+a[0][1]*b[1][0])%modify;
    c12 = (a[0][0]*b[0][1]+a[0][1]*b[1][1])%modify;
    c21 = (a[1][0]*b[0][0]+a[1][1]*b[1][0])%modify;
    c22 = (a[1][0]*b[0][1]+a[1][1]*b[1][1])%modify;
    vector <long long> tmp;
    tmp.push_back(c11); tmp.push_back(c12);
    c.push_back(tmp);
    tmp.clear();
    tmp.push_back(c21); tmp.push_back(c22);
    c.push_back(tmp);
    return c;
}
vector <vector<long long> > matrix_expo(vector <vector<long long> > m, long long p)
{
    if(p == 1)   return m;
    else{
        vector <vector<long long> > mp = matrix_expo(m, p/2);
        if(p%2 == 0)    return matrix_mul(mp, mp);
        else    return matrix_mul(m, matrix_mul(mp, mp));
    }
}

int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        long long a, b, n, m;
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        modify = 1;
        for(int i=1; i<=m; i++) modify*=10;
        vector <vector <long long> > ans;
        vector <long long> tmp;
        tmp.push_back(0); tmp.push_back(1);
        ans.push_back(tmp);
        tmp.clear();
        tmp.push_back(1); tmp.push_back(1);
        ans.push_back(tmp);
        if(n!=0){
                ans = matrix_expo(ans, n);
                printf("Case %d: %lld\n", t, (a*ans[0][0]+b*ans[1][0])%modify);
        }
        else    printf("Case %d: %lld\n", t, a%modify);
        ans.clear();
    }

    return 0;
}
