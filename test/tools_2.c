#include "pipex.h"

int		*ft_setup_pipes(int argc, char *infile, char *outfile)
{
	int	nb_child;
	int i;
	int *fd_tab;

	nb_child = 0;
	while (nb_child < (argc - 3))
		nb_child++;
	fd_tab = malloc(sizeof(int) * ((nb_child + 1)) * 2);
	if (!fd_tab)
		exit(1);
	nb_child += 1;
	i = 0;
	while (nb_child > 0)
	{
		if ((pipe(&fd_tab[i]) < 0))
		{
			perror("***ABORT: the system encountered an error while generating pipes");
			free(fd_tab);
			exit(1);
		}
		i += 2;
		nb_child--;
	}
	ft_set_input_output(fd_tab, infile, outfile, i);
	return (fd_tab);
}

void	ft_set_input_output(int *fd_tab, char *infile, char *outfile, int size)
{
	int fd1;
	int fd2;
	fd1 = open(infile, O_RDONLY);
	if (fd1 < 0)
		perror("ERROR: input file");
	else
	{
		dup2(fd1, fd_tab[0]);
		close(fd1);
	}
	fd2 = open(infile, O_RDONLY);
	if (fd1 < 0)
		perror("ERROR: input file");
	else
	{
		dup2(fd1, fd_tab[0]);
		close(fd1);
	}	


}