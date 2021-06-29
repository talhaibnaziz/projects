#include <bits/stdc++.h>
using namespace std;

int lps[1000010];
int main()
{
    int cases, t=0;
    scanf("%d", &cases);
    getchar();
    while(t++<cases)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        int len = pat.size();
        lps[0]=0; int pos=0;
        for(int i=1; i<len; i++)
        {
            if(pat[i]==pat[pos])
            {
                pos++;
                lps[i]=pos;
            }
            else
            {
                while(pos!=0 && pat[i]!=pat[pos]) pos=lps[pos-1];
                if(pos==0 && pat[i]!=pat[pos])  lps[i]=0;
                else lps[i]=++pos;
            }
        }
        /*for(int i=0; i<len; i++)    cout<<lps[i]<<' ';
        cout<<endl;*/
        int s = str.size();
        int cnt = 0;
        pos = 0; int ii = 0;
        while(ii<s)
        {
            if(str[ii]==pat[pos])
            {
                pos++;
                ii++;
                if(pos==len)
                {
                    pos = lps[pos-1];
                    cnt++;
                }
            }
            else
            {
                if(pos==0)  ii++;
                else pos = lps[pos-1];
            }
            //cout<<ii<<' '<<pos<<' '<<cnt<<endl;
        }
        printf("Case %d: %d\n", t, cnt);
    }

    return 0;
}
