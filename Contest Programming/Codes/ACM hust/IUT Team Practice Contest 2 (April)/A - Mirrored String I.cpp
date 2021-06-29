#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        string s;
        cin>>s;
        int len = s.length();
        bool possible = 1;
        for(int i=0; i<len/2; i++)
        {
            if(s[i]!=s[len-1-i] || (s[i]!='A' && s[i]!='H' && s[i]!='I' && s[i]!='M' && s[i]!='O' && s[i]!='T' && s[i]!='U' && s[i]!='V' && s[i]!='W' && s[i]!='X' && s[i]!='Y'))
            {
                possible = 0;
                break;
            }
        }
        if(len%2 && (s[len/2]!='A' && s[len/2]!='H' && s[len/2]!='I' && s[len/2]!='M' && s[len/2]!='O' && s[len/2]!='T' && s[len/2]!='U' && s[len/2]!='V' && s[len/2]!='W' && s[len/2]!='X' && s[len/2]!='Y'))  possible = 0;
        if(possible)    printf("yes\n");
        else     printf("no\n");
    }

    return 0;
}
