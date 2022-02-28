/*Теперь запустите свою программу memory-user, и в другом окне терминала на той же машине запустите программу free.
 Как при этом изменятся данные о свободной памяти? А что будет, когда вы снимете программу memory-user? Это совпадает с  
 вашими ожиданиями? Попробуйте задатьдругой объем запрашиваемой памяти. Что произойдет, если вы запросите очень много памяти?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
 int main(int argc, char *argv[]){

     if (argc != 3)
     {
         fprintf(stderr, "введите размер 'память' и 'время' работы");
         exit(EXIT_FAILURE);
     }
     
     int memory_size = atoi(argv[1]) * 1024 * 1024;
     int time_work = atoi(argv[2]);
     int *arr = malloc(memory_size);
     clock_t start = clock();
     double time_spent;
     int length = (int)(memory_size / sizeof(int));
     fprintf(stderr,"pid %d",getpid());

     while (1)
    {
        time_spent = (double)(clock() - start) / CLOCKS_PER_SEC;
        if (time_spent >= time_work)
            break;
        for (int i = 0; i < length; i++)
            arr[i] += 1;
    }
    printf("exit");
    return 0;
 }

 