#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int rpos, bpos, gpos, ypos;
    int rcnt=0, bcnt=0, gcnt=0, ycnt=0;
    int len = s.size();
    for(int i=0; i<len; i++)
    {
        if(s[i]=='R')   rpos = i%4;
        else if(s[i]=='B')  bpos = i%4;
        else if(s[i]=='G')  gpos = i%4;
        else if(s[i]=='Y')  ypos = i%4;
    }
    for(int i=0; i<len; i++)
    {
        if(s[i]=='!')
        {
            if(i%4==rpos)   rcnt++;
            else if(i%4==bpos)  bcnt++;
            else if(i%4==gpos)  gcnt++;
            else if(i%4==ypos)  ycnt++;
        }
    }
    printf("%d %d %d %d", rcnt, bcnt, ycnt, gcnt);

    return 0;
}
