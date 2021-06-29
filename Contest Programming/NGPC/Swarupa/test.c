#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#

int main()
{
    char a[10];
    scanf("%s", &a);
    a[strlen(a)] = 'g';
    strrev(a);
    int i;
    printf("%s", a);
    //for(i=0; i<=strlen(a); i++) printf("%c", a[i]);

    return 0;
}
