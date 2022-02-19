
/* Напишите программу которая открывает файл (с помощью системного вызова open()), а затем вызывает fork() для создания
нового процесса. Могут ли родитель и потомок обратиться к файловому дескриптору, возвращенному open()? 
Что произойдет, если они будут писать в файл одновременно?*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    
    int fd = open("C:/Users/nypro/projects/test.txt", O_CREAT|O_WRONLY);
    int rc = fork();
    if (rc < 0)
    {
        close(fd);
        fprintf(stderr,"error");
        exit(1);
    }else if (rc == 0)
    {
        char *s = "child write\n";
        write(fd,s,strlen(s));
    }else{
        wait(NULL);
        char *s = "parent write\n";
        write(fd,s,strlen(s));
        close(fd);
    }
    return 0;    
}
/*
in test.txt:
child write
parent write*/

