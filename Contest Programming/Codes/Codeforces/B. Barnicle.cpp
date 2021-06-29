#include <bits/stdc++.h>
using namespace std;

int main()
{
    char num[200];
    char ans[200], tmp[5], chck[110];
    cin>>num;
    int len=strlen(num);
    int i, ipos, epos, j;
    //finding position of point
    for(i=0; i<len; i++)
    {
        if(num[i]=='.') break;
        ans[i]=num[i];
    }
    ipos=i;
    //finding position of e
    for(i=ipos+1, j=0; i<len; i++, j++)
    {
        if(num[i]=='e') break;
        chck[j]=num[i];
    }
    chck[j]='\0';
    epos=i;
    //finding power
    for(i=epos+1, j=0; i<len; i++, j++)
    {
        tmp[j]=num[i];
    }
    tmp[j]='\0';
    int loop=atoi(tmp);
    //changing position of point
    for(i=ipos+1, j=0; j<loop; i++, j++)
    {
        if(i>=epos)  ans[i-1]='0';
        else ans[i-1]=num[i];
    }
    int c=atoi(chck);
    if(i<epos && c!=0) ans[i-1]='.';
    else ans[i-1]='\0';
    for( ; i<epos; i++)
    {
        ans[i]=num[i];
    }
    ans[i]='\0';

    cout<<ans;

    return 0;
}
