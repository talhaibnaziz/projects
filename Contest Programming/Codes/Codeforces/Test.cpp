#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("in.txt");
    for(int i=0; i<5000; i++)   fout<<'a';
    fout<<'\0';
    return 0;
}
