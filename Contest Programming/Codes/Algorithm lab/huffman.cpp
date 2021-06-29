#include <bits/stdc++.h>
using namespace std;
struct node
{
    int id;
    int freq;
    string s;
    int lft;
    int rt;
    bool operator < (const node &n) const
    {
        return freq>n.freq;
    }
};
node arr[1000];
int avail=0;
string code;
void encode(node n, char ch)
{
    string strleft, strright;
    int lft=n.lft, rt=n.rt;
    if(lft!=-1) strleft=arr[lft].s;
    if(rt!=-1)  strright=arr[rt].s;
    for(int i=0; i<strleft.size(); i++)
    {
        if(strleft[i]==ch)
        {
            code+="1";
            encode(arr[lft], ch);
        }
    }
    for(int i=0; i<strright.size(); i++)
    {
        if(strright[i]==ch)
        {
            code+="0";
            encode(arr[rt], ch);
        }
    }
}
node root;
void decode(int idx, node n)
{
    if(n.s.size()==1)
    {
        cout<<n.s;
        if(idx!=code.size())    decode(idx, root);
        return;
    }
    if(code[idx]=='0')  decode(idx+1, arr[n.rt]);
    else if(code[idx]=='1') decode(idx+1, arr[n.lft]);
}
int main()
{
    string str;
    for(int i=0; i<1000; i++)
    {
        arr[i].freq=0;
        arr[i].lft=-1;
        arr[i].rt=-1;
        arr[i].id=i;
    }
    freopen("in.txt", "r", stdin);
    getline(cin, str);
    int freq[300]={0};
    for(int i=0; i<str.size(); i++)
    {
        freq[str[i]]++;
    }
    priority_queue <node> q;
    for(int i=0; i<=300; i++)
    {
        if(freq[i]!=0)
        {
            arr[avail].freq=freq[i];
            arr[avail].s+=i;
            q.push(arr[avail]);
            avail++;
        }
    }
    while(q.size()!=1)
    {
        node a, b;
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        arr[avail].freq=b.freq+a.freq;
        arr[avail].id=avail;
        arr[avail].s=b.s+a.s;
        arr[avail].lft=b.id;
        arr[avail].rt=a.id;
        q.push(arr[avail]);
        avail++;
    }
    for(int i=0; i<str.size(); i++) encode(q.top(), str[i]);
    cout<<code<<endl;
    root=q.top();
    decode(0, root);

    return 0;
}
