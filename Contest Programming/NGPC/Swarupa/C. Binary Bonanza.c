/*NGPC'17 Preliminary : C.Binary bonanza*/

#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,n,s1,s2,j,k;
    char A[10005]={},B[10005]={};
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%s",A);
        scanf("%s",B);
        s1=strlen(A);
        s2=strlen(B);
        if(s1>s2)
        {
            strrev(B);
            for(k=s2;k<=(s1-1);k++)
            {
                B[k]='0';
            }
            B[s1]='\0';
            strrev(B);
        }
        else if(s1<s2)
        {
            strrev(A);
            for(k=s1;k<=(s2-1);k++)
            {
                A[k]='0';
            }
            A[s2]='\0';
            strrev(A);
        }
//        printf("%s %s\n", A, B);
        j=strcmp(A,B);
        if(j==1)
            printf("Case %d: A",i);
        else if(j==0)
            printf("Case %d: Same",i);
        else
            printf("Case %d: B",i);

        if(i!=t)
            printf("\n");
//        memset(A,'\0',sizeof(A));
//        memset(B,'\0',sizeof(B));
    }
    return 0;
}
