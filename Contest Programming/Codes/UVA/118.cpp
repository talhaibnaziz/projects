#include <bits/stdc++.h>
using namespace std;

int m, n;
bool scent[55][55];
int dirx = {0,1,0,-1};
int diry = {1,0,-1,0};
int turnleft = {};
int turnright = {};
string dir = "NESW";
int dirint;

int main()
{
    while(cin>>m>>n)
    {
        int startx, starty;
        char orient;
        string input;
        cin>>startx>>starty>>orient;
        cin>>input;
        if(orient=='N') dir = 0;
        else if(orient=='E')    dir = 1;
        else if(orient=='S')    dir = 2;
        else    dir = 3;
        int len = input.size();
        for(int i=0; i<len; i++)
        {
            if(input[i]=='R')   dir++;
            else if(input[i]=='L')  dir--;
            if(dir==4)  dir = 0;
            else if(dir==0) dir = 3;
        }
    }
    return 0;
}
