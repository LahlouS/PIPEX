
#include <sys/types.h> //pour le type pid_t
#include <sys/wait.h> //pour la fonction wait
#include <unistd.h> //pour fork
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

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

// void fils(int i)
// {
// 	printf("\n\n\tfils %d en cours de destruction...\n", i);
// 	sleep(2);
// 	exit(i);
// }

/*EXEMPLE DE CREATION DE 2 FILS AVEC UTILISATION DE &status POUR LETAT DE FIN DEXECUTION DU PROCESSUS ENFANT*/

// int main (void)
// {
// 	int x = 0;
// 	int status;
// 	printf("\n\t\tIS FIRST --> processus courant = %d, processus parent = %d\n\n", getpid(), getppid());

// 	if (fork())
// 	{
// 		printf("\n\t\tprocessus courant = %d, processus parent = %d\n\n", getpid(), getppid());
// 		if (fork() == 0)
// 		{
// 			printf("\n\t\tFILS 2 --> processus courant = %d, processus parent = %d\n\n", getpid(), getppid());
// 			fils(2);
// 		}
// 	}
// 	else
// 	{
// 		printf("\n\t\tFILS 1 --> processus courant = %d, processus parent = %d\n\n", getpid(), getppid());
// 		fils (1);
// 	}
// 	if (wait(&status) > 0)
// 	{
// 		status >>= 8;
// 		printf("fin du fils %d\n", status);
// 	}
// 	if (wait(&status) > 0)
// 	{
// 		status >>= 8;
// 		printf("fin du fils %d\n", status);
// 	}
// 	x++;
// 	printf("x = %d\n", x);
// 	return (0);
// }

/*EXEMPLE DE PROCESSUS ZOMBIE CAR LE PERE N'ATTEND PAS LE FILS*/

// int main(void)
// {
// 	pid_t pid = fork();

// 	if (pid > 0)
// 	{
// 		sleep(30);
// 	}
// 	else if (pid == 0)
// 	{
// 		exit(1);
// 	}
// 	return (0);
// }

// int main(void)
// {
// 	pid_t pid;

// 	pid = fork();

// 	if (pid)
// 	{
// 		printf("ICI le processus pere: PID = %d, PID parent = %d\n", getpid(), getppid());
// 		sleep(3);
// 	}
// 	else
// 	{
// 		printf("ICI le processus fils: PID = %d, PID parent = %d\n", getpid(), getppid());
// 		sleep(15);
// 		printf("ICI le processus fils, ADOPTE: PID = %d, PID parent = %d\n", getpid(), getppid());
// 		exit(1);

// 	}
// 	return 0;
// }


// int main(int ac, char **av)
// {
// 	pid_t pid = fork();
// 	int	status = 0;
// 	(void)ac;
// 	printf("programme originel :\n\tpid = %d, pid pere = %d\n\n", getpid(), getppid());
// 	if (pid == 0)
// 	{
// 		if (execv("./test2", av) < 0)
// 			printf("ERREUR : %s\n", strerror(errno));
// 		exit(1);
// 	}
// 	else
// 	{
// 		wait(&status);
// 		printf("LE PERE ATTEND SON FILS: status apres le wait %d\n", status >> 8);
// 	}
// 	return 0;
// }

// char	**ft_split(char const *s, char c);
// int main(void)
// {
// 	char 
// 	return 0;
// }
 #define BUFFER_SIZE 500

 size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
        {
			return (s1[i] - s2[i]);
        }
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
        i++;
	}
	return (0);
}

// int main (void)
// {
//     char *here_doc = "HERE";
//     char *buf[BUFFER_SIZE];
//     int read_ret;
//     int fd[2];
//     int pid;

//     pipe(fd);
//     pid = fork();
//     if (pid < 0)
//     {
//         printf("erreur fork\n");
//         exit (1);
//     }
//     else if (pid)
//     {
//         read_ret = read(0, buf, BUFFER_SIZE);

//     }
//     return (0);
// }

int main(void)
{
    char buf[BUFFER_SIZE];
    char *here_doc = "HERE";
    int read_ret = 1;
    int i = 0;
    int fd[2];
    int pid;

    pipe(fd);
    while (read_ret)
    {
        write(1, "pipe heredoc> ", 14);
        read_ret = read(0, buf, BUFFER_SIZE);
        buf[read_ret] = '\0';
        if (!(ft_strncmp(buf, here_doc, ft_strlen(here_doc))))
            break ;

        write(fd[1], buf, ft_strlen(buf));
    }
    puts("\n");
    close(fd[1]);
    pid = fork();
    if (!pid)
    {
        char buf2[500];
        close(fd[1]);
        int test = read(fd[0], buf2, 500); 
        buf2[test] = '\0';
        printf("%s", buf2);
    }
    else
        wait(NULL);
    
    return (0);
}