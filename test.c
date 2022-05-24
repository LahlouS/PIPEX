
#include <sys/types.h> //pour le type pid_t
#include <sys/wait.h> //pour la fonction wait
#include <unistd.h> //pour fork
#include <stdio.h>
#include <stdlib.h>

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

// int main (void)
// {
//     int i, n = 5;
//     int child_pid;

//     for (i = 1; i < n; i++)
//     {
//         if ((child_pid = fork()) <= 0 ) break;
//             printf("Processus en cour = %d, processus parent = %d, i = %d\n", getpid(), getppid(), i);
//     }
//     return (0);
// }

// int main(void)
// {
//     int i, n = 5;
//     pid_t pid;
//     int test = getpid();

//     printf("\n\t\t AVANT LE FORKS \n\t\tprocessus courant = %d, processus parent = %d\n\n", getpid(), test);

//     for (i = 1; i < n; i++)
//     {
//         if ((pid = fork()) == -1) break;

//         if (pid == 0)
//         {
//             if (getppid() == test)
//                 printf("FIRST LAYER-->  ");
//             printf("processus courant = %d, processus pere = %d, i = %d\n", getpid(), getppid(), i);
//         }
        
//     }
//     return (0);
// }


// int main(void)
// {
//     pid_t pid = 0;

//     printf("processus courant = %d, processus pere = %d\n", getpid(), getppid());

//     pid = fork();
//     printf("processus courant = %d, processus pere = %d\n", getpid(), getppid());
    
//     return (0);
// }

// int main(void)
// {
//     int i, n = 5;
//     pid_t pid = 0;
//     int test = getpid();

//     printf("\n\t\t AVANT LE FORKS \n\t\tprocessus courant = %d, processus parent = %d\n\n", test, getppid());

//     for (i = 1; i < n; i++)
//     {
//         if ((pid = fork()) == -1) break ;
//         if (pid == 0)
//             printf("Processus courant = %d et processus pere = %d, i = %d\n\n", getpid(), getppid(), i);
//     }
//     while (wait(NULL) >= 0);

//     return (0);
// }

void fils(int i)
{
    printf("\n\n\tfils %d en cours de destruction...\n", i);
    sleep(2);
    exit(i);
}

int main (void)
{
    int status;
    printf("\n\t\tprocessus courant = %d, processus parent = %d\n\n", getpid(), getppid());

    if (fork())
    {
        if (fork() == 0)
            fils(2);
    }
    else
        fils (1);
    printf("\n\t\tprocessus courant = %d, processus parent = %d\n\n", getpid(), getppid());
    if (wait(&status) > 0)
         printf("fin du fils %d\n", status >> 8);
    if (wait(&status) > 0)
        printf("fin du fils %d\n", status >> 8);
    return (0);
}