
/* Напишите программу, вызывающую fork(). Но прежде чем вызвать fork(),главный процесс должен присвоить какой-нибудь 
переменной (скажем,x) какое-то значение (скажем, 100). Какое значение эта переменная будет иметь в дочернем процессе? 
Что произойдет с переменной x, если и родитель, и потомок изменят ее значение? */

#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int 
main(int argc, char const *argv[])
{
    int x = 100;
    printf("parent process (pid:%d)\n ",(int) getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if (rc == 0)
    {
        x = 111;
        printf("x  = %d in child process (pid:%d)\n ", x, (int) getpid());
    }else{
        wait(NULL);
        x = 222;
        printf("x  = %d in parent process (pid:%d)\n ", x, (int) getpid());
        
    }
    return 0;
}
/* Output:
parent process (pid:1395)
x  = 111 in child process (pid:1396)
x  = 222 in parent process (pid:1395)*/

