#include <bits/stdc++.h>
using namespace std;

int main()
{
    string linear = "AEFHIKLMNTVWXYZ";
    string input;
    int lincnt = 0;
    cin>>input;
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<linear.size(); j++)
        {
            if(input[i]==linear[j]) lincnt++;
        }
    }
    if(lincnt == 0 || lincnt == input.size())   cout<<"YES";
    else    cout<<"NO";

    return 0;
}
