#include <bits/stdc++.h>
using namespace std;

int main ()
{
  freopen("typetest.txt", "r", stdin);
  char ch;
  int cnt = 0;
  while(scanf("%c", &ch)!=EOF)
  {
      printf("%c", ch);
      cnt++;
  }
  printf("\nCharacters: %d\n", cnt);
  printf("\nWords: %d\n", cnt/5);
  return 0;
}
