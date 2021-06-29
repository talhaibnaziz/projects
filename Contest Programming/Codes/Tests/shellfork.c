#include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t cpid;
    cpid = fork();
    if(cpid==0)
    {
        printf("Child process\n");
    }
    else
    {
        printf("parent process\n");
    }
    return 0;
}
