#include "pipex.h"

int main(int ac, char **av)
{
    int fds[6];
    char *infile = *(av + 1);
    char *outfile = *(av + (ac - 1));
    char **args1 = ft_split(*(av + 2), ' ');
    char **args2 = ft_split(*(av + 3), ' ');
    int pid;
    int fd_1;
    int fd_2;
    pipe(&fds[0]);
    pipe(&fds[2]);
    pipe(&fds[4]);
    fd_1 = open(infile, O_RDONLY);
    if (fd_1 < 0)
    {
        printf("erreur ouverture infile\n");
        return (0);
    } 
    fd_2 = open(outfile, O_CREAT| O_WRONLY, 0777);
    if (fd_1 < 0)
    {
        printf("erreur ouverture outfile\n");
        return (0);
    }
    dup2(fd_1, fds[0]);
    close(fd_1);
    dup2(fd_2, fds[5]);
    close(fd_2);
    close(fds[1]);
    printf("ICI le processus pere : PID = %d, parent = %d\n", getpid(), getppid());
    pid = fork();
    if (!pid) //child process
    {
    printf("ICI le processus FILS 1 : PID = %d, parent = %d\n", getpid(), getppid());
       dup2(fds[0], 0);
       close(fds[0]);
       close(fds[1]);
       dup2(fds[3], 1);
       close(fds[3]);
       if (execve(*args1, args1, NULL) < 0)
        {
            printf("erreur execve fils 1\n");
            return (0);
        }
    }
    else // in parent process
    {
        pid = fork();
        if (!pid) // in child process
        {
            dup2(fds[2], 0);
            close(fds[2]);
            close(fds[3]);
            dup2(fds[5], 1);
            close(fds[5]);
            if (execve(*args2, args2, NULL) < 0)
            {
                printf("erreur execve fils 2\n");
                return (0);
            }
        }
    }
    for (int i = 0;i<6;i++)
        close(fds[i]);
    if (wait(NULL) < 0)
        puts("erreur attente fils 1"); 
    if (wait(NULL) < 0)
        puts("erreur attente fils 2");
}