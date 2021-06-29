#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=0, cases, n;
    int b, w, draw;
    string str;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n;
        cin>>str;
        b=0; w=0; draw=0;
        for(int i=0; i<n; i++)
        {
            if(str[i]=='B') b++;
            else if(str[i]=='W')    w++;
            else if(str[i]=='T')
            {
                b++;
                w++;
                draw++;
            }
        }
        cout<<"Case "<<t<<": ";
        if(b==0 && w==0)    cout<<"ABANDONED";
        else if(b==0)   cout<<"WHITEWASH";
        else if(w==0)   cout<<"BANGLAWASH";
        else if(b>w)    cout<<"BANGLADESH "<<b-draw<<" - "<<w-draw;
        else if(b==w)   cout<<"DRAW "<<w-draw<<" "<<draw;
        else    cout<<"WWW "<<w-draw<<" - "<<b-draw;
        cout<<'\n';
    }

    return 0;
}
