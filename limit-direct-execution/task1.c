/*В этом домашнем задании вам предстоит измерить стоимость системного вызова и контекстного переключения*/

#include<stdio.h>
#include<fcntl.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    int fd = open("./test.txt", O_CREAT | O_WRONLY), loops = 1000;
    struct timeval start, end;
    
    gettimeofday(&start,NULL);
    for (int i = 0; i < loops; i++)
    {
        read(fd,NULL,0);
    }
    gettimeofday(&end,NULL);
    
    printf("Cтоимость системного вызова в микросекундах %f", (end.tv_usec - start.tv_usec) / (float)loops);
    close(fd);

    /*--------------------------------------------------------------------------------------------------------*/
    int fd1[2]; 
    int fd2[2];
    
    if (pipe(fd1) == -1 || pipe(fd2) == -1)
    {
        fprintf(stderr, "Pipe Failed");
        exit(1);
    }
    int rc = fork();

    
    if (rc < 0)
    {
        fprintf(stderr, "error");
        exit(1);
    }else if (rc == 0)
    {
        for (size_t i = 0; i < 100; i++)
        {
            write(fd1[1],NULL,0);
            read(fd2[0],NULL,0);
        }
        
    }else{

        gettimeofday(&start,NULL);
        for (size_t i = 0; i < 100; i++)
        {
            read(fd1[0],NULL,0);
            write(fd2[1],NULL,0);
        }
        gettimeofday(&end,NULL);
        printf("Cтоимость контекстного переключения в микросекундах %f \n", (end.tv_usec - start.tv_usec) / (float)loops);
    }
    
    
    

    return 0;
}

/*
Conceptually, a pipe is a connection between two processes
Parameters :
fd[0] will be the fd(file descriptor) for the 
read end of pipe.
fd[1] will be the fd for the write end of pipe.
Returns : 0 on Success.
-1 on error.
Output:
Cтоимость системного вызова в микросекундах 0.072000

*/
