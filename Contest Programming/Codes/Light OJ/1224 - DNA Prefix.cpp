#include <bits/stdc++.h>
using namespace std;
struct node
{
	int cnt;
	node *next[4+1];
	node()
	{
		cnt=0;
		for(int i=0;i<4;i++) next[i]=NULL;
	}
}*root;

void insrt(char *str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id;
		if(str[i]=='A') id=0;
		else if(str[i]=='C')    id=1;
		else if(str[i]=='G')    id=2;
		else id=3;
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
		curr->cnt++;
	}
}
int srch(node *cur, int level)
{
    int ans=0;
	for(int i=0; i<4; i++)
    {
        if(cur->next[i])    ans=max(ans, srch(cur->next[i], level+1));
    }
    return max(ans, level*cur->cnt);
}
void del(node *cur)
{
      for(int i=0;i<4;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;


         delete(cur) ;
}
int main(){
	int cases, t=0;
	scanf("%d", &cases);
	while(t++<cases)
    {
        int n;
        root=new node();
        char str[60];
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%s", &str);
            insrt(str, strlen(str));
        }
        printf("Case %d: %d\n", t, srch(root, 0));
        del(root);
    }

	return 0;
}
