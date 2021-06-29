#include <bits/stdc++.h>
using namespace std;
#define debug cout<<"I am here"<<endl;
struct node
{
	bool endmark;
	node *next[10+1];
	node()
	{
		endmark=false;
		for(int i=0;i<10;i++) next[i]=NULL;
	}
}*root;

void insrt(char *str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endmark=true;

}
bool srch(node *cur)
{
    bool flag=0;
	for(int i=0; i<10; i++)
    {
        if(cur->next[i] && cur->endmark)    return 1;
        else if(cur->next[i])   flag=(flag || srch(cur->next[i]));
    }

    return flag;
}
void del(node *cur)
{
    for(int i=0;i<10;i++) if(cur->next[i])    del(cur->next[i]);
    delete(cur) ;
}
int main(){
    //freopen("out.txt", "w", stdout);
	int t=0, cases;
	scanf("%d", &cases);
	while(t++<cases)
    {
        int n;
        scanf("%d", &n);
        getchar();
        root=new node();
        for(int i=0; i<n; i++)
        {
            char str[15];
            scanf("%s", &str);
            insrt(str, strlen(str));
        }
        if(srch(root))  printf("Case %d: NO\n", t);
        else printf("Case %d: YES\n", t);
        del(root);
    }

	return 0;
}
