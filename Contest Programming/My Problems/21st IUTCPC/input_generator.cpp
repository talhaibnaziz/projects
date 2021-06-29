#include <bits/stdc++.h>
using namespace std;

void max_graph_generator()
{
    freopen("weighted_max_input.txt", "w", stdout);
    cout<<10<<endl;
    for(int i=1; i<=10; i++)
    {
        cout<<"100000 100000 20000 40000 60000 80000"<<endl;
        int u = 1, v = 2;
        for(int j=1; j<=100000; j++)
        {
            cout<<u<<" "<<v<<" "<<"100000"<<endl;
            v++;
            if(v==u)    v++;
            if(v==100001)
            {
                v = 1;
                u++;
            }
            if(u==100001)
            {
                u = 1;
                v = 1;
            }
        }
    }
}
void random_graph_generator()
{
    freopen("weighted_random_input.txt", "w", stdout);
    cout<<10<<endl;
    srand(time(NULL));
    for(int i=1; i<=10; i++)
    {
        int n, m, a, b, c, r;
        n = (rand()%100000)+1;
        m = (((rand()%100000)+n)%100000)+1;
        a = (rand()%n)+1;
        b = (rand()%n)+1;
        c = (rand()%n)+1;
        r = (rand()%n)+1;
        cout<<n<<" "<<m<<" "<<a<<" "<<b<<" "<<c<<" "<<r<<endl;
        for(int j=0; j<m; j++)
        {
            int u = (rand()%n)+1;
            int v = (rand()%n)+1;
            int w = (rand()%100000)+1;
            if(u==v)
            {
                j--;
                continue;
            }
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
}

int main()
{
    //all complete graph of highest size
    ios_base::sync_with_stdio(false);
    max_graph_generator();
//    random_graph_generator();

    return 0;
}
