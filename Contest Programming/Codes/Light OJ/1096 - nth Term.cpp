#include <bits/stdc++.h>
using namespace std;

long long matrix[4][4];
long long dpmatrix[30][4][4];
long long tmpmatrix[4][4];
void matrix_mul(long long a[4][4], long long b[4][4], long long c[4][4])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            a[i][j]=0;
            for(int k=0; k<4; k++)
            {
                a[i][j] += (b[i][k]*c[k][j])%10007;
            }
            a[i][j] %= 10007;
        }
    }
}
void rec(long long n, int step)
{
    if(n==1){
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)  dpmatrix[step][i][j]=matrix[i][j];
        }
        return;
    }
    rec(n/2, step+1);
    /*cout<<step+1<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)  cout<<dpmatrix[step+1][i][j]<<' ';
        cout<<endl;
    }*/
    matrix_mul(dpmatrix[step], dpmatrix[step+1], dpmatrix[step+1]);
    if(n%2==0)  return;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            tmpmatrix[i][j]=dpmatrix[step][i][j];
        }
    }
    matrix_mul(dpmatrix[step], matrix, tmpmatrix);
}
int main()
{
    int t=0, cases;
    scanf("%d", &cases);
    memset(matrix, 0, sizeof matrix);
    matrix[0][1]=1; matrix[1][2]=1; matrix[3][3]=1;
    while(t++<cases)
    {
        long long n, a, b, c;
        scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
        matrix[0][0]=a; matrix[2][0]=b; matrix[3][0]=c;
        if(n<=2)    printf("Case %d: 0\n", t);
        else
        {
            rec(n-2, 0);
            printf("Case %d: %lld\n", t, dpmatrix[0][3][0]%10007);
        }
    }

    return 0;
}
