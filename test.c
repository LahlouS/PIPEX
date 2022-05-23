#include <sys/types.h> //pour le type pid_t
#include <unistd.h> //pour fork
#include <stdio.h>

// int main(void)
// {
//     int i, j, k, n = 3;

//     pid_t fils_pid;

//     for (i = 1; i < n; i++)
//     {
//         fils_pid = fork();
//         if (fils_pid > 0)
//             break ;
//         printf("processus %d avec pere %d\n", getpid(), getppid());

//     }
//      //for (j = 0; j < 1000000; j++);
//     //     for (k = 0; k < 100000; k++);
    
//     return (0);
// }

int main (void)
{
    int i, n = 5;
    int child_pid;

    for (i = 1; i < n; i++)
    {
        if ((child_pid = fork()) <= 0 ) break;
            printf("Processus en cour = %d, processus parent = %d, i = %d\n", getpid(), getppid(), i);
    }
    return (0);
}