#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, t=0, n, x;
    char choice;
    scanf("%d", &T);
    while(t++<T)
    {
        scanf("%d", &n);
        printf("Case %d:\n", t);
        stack <pair<int, int> > max_st;
        stack <pair<int, int> > serial_st;
        for(int i=0; i<n; i++)
        {
            getchar();
            scanf("%c", &choice);
            if(choice == 'A')
            {
                scanf("%d", &x);
                serial_st.push(make_pair(i, x));
//                cout<<"Pushing: "<<x<<endl;
                if(max_st.empty() || x > max_st.top().second)
                {
//                    cout<<"Maxing: "<<x<<endl;
                    max_st.push(make_pair(i, x));
                }
            }
            else if(choice == 'Q')
            {
                if(serial_st.empty())   printf("Empty\n");
                else    printf("%d\n", max_st.top().second);
            }
            else
            {
                if(serial_st.empty())    continue;
                else
                {
                    if(max_st.top().first == serial_st.top().first)
                    {
//                        cout<<"Max Popping: "<<max_st.top().second<<endl;
                        max_st.pop();
                    }
//                    cout<<"Popping: "<<serial_st.top().second<<endl;
                    serial_st.pop();
                }
            }
        }
    }

    return 0;
}
