#include <stdio.h>
#include <unistd.h> //excv / read / write / close
#include <stdlib.h>
#include <sys/wait.h> //pour la fonction wait
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define W 1
#define R 0

int main(int argc, char **argv, char **envp)
{
	pid_t pid;
	char *args[] = {"/bin/ls", "-l", NULL};
	int pipe_fd[2];
	//int file_fd[2];
	char buf[BUFFER_SIZE];
	
	// file_fd[0] = open("outfile.txt", O_WRONLY);
	// if (file_fd[0] == -1)
	// {
	// 	printf("OPEN: erreur ouverture outfile: %s\n\n", strerror(errno));
	// 	exit(1);
	// }
	pipe(pipe_fd);
	pid = fork();
	if (pid)
	{
		printf("--> PERE, PID = %d, PID parent = %d\n\n", getpid(), getppid());
		if (wait(NULL) < 0)
		{
			printf("WAIT: erreur wait, exit prgm");
			exit(1);
		}
	}
	else
	{
		printf("--> FILS 1, PID = %d, PID parent = %d\n\n", getpid(), getppid());
		close(pipe_fd[R]); // ici je ferme le canal de lecture car la commande cat ne va qu'ecrire dans le tube
		dup2(pipe_fd[W], 1); // ici je duplique mon pipe_fd d'ecriture sur 1, ainsi, mon pipe_fd devient la sortie d'ecriture std
		if (execve(*args, args, envp) < 0)
		 	printf("FILS 1: EXECVE: Erreur commutation de processus: %s\n", strerror(errno));
	}
	//close(pipe_fd[W]); // fermture du canal d'ecriture car je n'ai besion que de la lecture
	int read_ret = read(pipe_fd[R], buf, BUFFER_SIZE);
	printf("read_ret = %d", read_ret);
	buf[read_ret] = 0;
	printf("\n\tPERE PID = %d et parent PID = %d\n\tRETOUR DE LA COMMANDE CAT: \n<< %s >>\n\t  normalement mon fils a fini son travaille alors je peux m'eteindre\n\n", getpid(), getppid(), buf);
//	pipe(pipe_fd);
	
	return (0);
}