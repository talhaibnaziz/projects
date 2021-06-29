#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=0, cases, n, m;
    cin>>cases;
    while(t++<cases)
    {
        cin>>n>>m;
        long long minsal[1005];
        long long offsal[1005];
        long long maxjob[1005];
        string qual[1005];
        bool employed[1005]={0};
        for(int i=0; i<n; i++)  cin>>minsal[i];
        for(int i=0; i<m; i++)  cin>>offsal[i]>>maxjob[i];
        for(int i=0; i<n; i++)  cin>>qual[i];
        int candans = 0;
        long long salans = 0;
        int companyans = 0;
        for(int i=0; i<n; i++)
        {
            long long current = 0;
            int company;
            for(int j=0; j<m; j++)
            {
                if(qual[i][j]=='1' && maxjob[j]>0 && offsal[j]>current)
                {
                    current = offsal[j];
                    company = j;
                }
            }
            if(current != 0 && current>=minsal[i])
            {
                candans++;
                salans += current;
                maxjob[company]--;
                employed[company] = 1;
                //cout<<current<<' '<<company<<endl;
            }
        }
        for(int i=0; i<m; i++)  if(!employed[i])    companyans++;
        cout<<candans<<' '<<salans<<' '<<companyans<<"\n";
    }

    return 0;
}
