#include <bits/stdc++.h>
using namespace std;

/*struct node
{
	short endmark;
	node *next[52+1];
	node()
	{
		endmark=0;
		for(int i=0;i<52;i++) next[i]=NULL;
	}
}*root;

void insrt(string str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id;
		if(str[i]<='z' && str[i]>='a')  id=str[i]-'a';
        else    id=str[i]-'A'+26;
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endmark++;
	cout<<sizeof root<<endl;
	//cout<<str<<": "<<curr->endmark<<endl;
}
int srch(string str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id;
		if(str[i]<='z' && str[i]>='a')  id=str[i]-'a';
        else    id=str[i]-'A'+26;
		if(curr->next[id]==NULL) return 0;
		curr=curr->next[id];
	}
	return curr->endmark;
}
void del(node *cur)
{
      for(int i=0;i<52;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;


         delete(cur) ;
}*/
map <string, int> mp;
int main()
{
    //freopen("out.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    int t=0, cases;
    cin>>cases;
    while(t++<cases)
    {
        int n, m;
        cin>>n;
        string tempor;
        getline(cin, tempor);
        //root = new node();
        for(int i=0; i<n; i++)
        {
            string str;
            cin>>str;
            string s;
            s.push_back(str[0]);
            str.erase(str.begin());

            if(str.size()!=0)
            {
                s.push_back(str[str.size()-1]);
                str.erase(str.end()-1);
            }
            if(str.size()!=0)
            {
                sort(str.begin(), str.end());
                s = s + str;
            }
            //cout<<s<<endl;
            //insrt(s, s.size());
            if(mp.count(s)!=0)  mp[s]++;
            else mp[s]=1;
            //cout<<s<<' '<<mp[s]<<endl;
        }
        int ans;
        cin>>m;
        getline(cin, tempor);
        cout<<"Case "<<t<<":\n";
        for(int i=0; i<m; i++)
        {
            string str;
            ans=1;
            getline(cin, str);
            int len = str.size();
            string tmp;
            for(int i=0; i<len; i++)
            {
                tmp.push_back(str[i]);
                if(str[i]==' ')
                {
                    string s;
                    tmp.erase(tmp.end()-1);
                    if(tmp.size()==0)   continue;
                    s.push_back(tmp[0]);
                    tmp.erase(tmp.begin());

                    if(tmp.size()!=0)
                    {
                        s.push_back(tmp[tmp.size()-1]);
                        tmp.erase(tmp.end()-1);
                    }
                    if(tmp.size()!=0)
                    {
                        sort(tmp.begin(), tmp.end());
                        s = s + tmp;
                        tmp.clear();
                    }
                    int ret;
                    if(mp.count(s)!=0)  ret = mp[s];
                    //ret = srch(s, s.size());
                    ans = ans * ret;
                    //cout<<s<<' '<<ret<<' '<<ans<<endl;
                }
            }
            string s;
            if(tmp.size()!=0)
            {
                s.push_back(tmp[0]);
                tmp.erase(tmp.begin());

                if(tmp.size()!=0)
                {
                    s.push_back(tmp[tmp.size()-1]);
                    tmp.erase(tmp.end()-1);
                }
                if(tmp.size()!=0)
                {
                    sort(tmp.begin(), tmp.end());
                    s = s + tmp;
                    tmp.clear();
                }
                int ret;
                if(mp.count(s)!=0)  ret = mp[s];
                else ret=0;
                //ret = srch(s, s.size());
                ans = ans * ret;
                //cout<<s<<' '<<ret<<' '<<ans<<endl;
            }
            cout<<ans<<"\n";
        }
        //del(root);
        mp.clear();
    }

    return 0;
}

