#include <bits/stdc++.h>
using namespace std;

int s[100]={1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12}, f[100]={4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
int v[100]={20, 30, 11, 45, 78, 80, 45, 66, 33, 27, 4};

int find_max(int idx, int time)
{
    if(idx==11) return 0;
    //cout<<idx<<' '<<time<<endl;
    if(time>s[idx])   return find_max(idx+1, time);
    else return max(v[idx]+find_max(idx+1, f[idx]), find_max(idx+1, time));
}
int main()
{
    for(int i=0; i<10; i++)
    {
        for(int j=i+1; j<11; j++)
        {
            if(f[i]>f[j])
            {
                swap(f[i], f[j]);
                swap(s[i], s[j]);
                swap(v[i], v[j]);
            }
        }
    }
    for(int i=0; i<11; i++) printf("%3d", s[i]);
    cout<<endl;
    for(int i=0; i<11; i++) printf("%3d", f[i]);
    cout<<endl;
    for(int i=0; i<11; i++) printf("%3d", v[i]);
    cout<<endl;
    cout<<find_max(0, 0)<<endl;

    return 0;
}
