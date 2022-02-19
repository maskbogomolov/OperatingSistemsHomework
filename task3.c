/*Напишите еще программу, в которой используется fork(). Дочерний процесс должен напечатать «hello», а родительский процесс
 – «goodbye». Сделайте так, чтобы дочерний процесс всегда печатал свое сообщение первым. Сможете ли вы сделать это, 
 не вызывая wait() в родителе?*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
 int main(){

     int rc = fork();

     if (rc < 0)
     {
         printf("error");
         exit(1);
     }else if (rc == 0)
     {
         printf("hello\n");
     }else{
         sleep(2);
         printf("goodbye");
     }
     return 0;
 }
 /*
Output:
hello
goodbye
*/