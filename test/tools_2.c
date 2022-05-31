#include "pipex.h"

int		*ft_setup_pipes(int argc, char **argv)
{
	int	nb_child;
	int i;
	int *fd_tab;

	nb_child = argc - (3 + ft_get_nb_child(*(argv + 1)));
	fd_tab = malloc(sizeof(int) * ((nb_child + 1)) * 2);
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
	if (!(ft_get_nb_child(*(argv + 1))))
		ft_set_input_output(fd_tab, *(argv + 1), *(argv + argc - 1), i);
	else
		ft_set_heredoc(fd_tab, *(argv + 2),*(argv + argc - 1), i);
	return (fd_tab);
}

void	ft_set_input_output(int *fd_tab, char *input, char *output, int size)
{
	int fd1;
	int fd2;
	fd1 = open(input, O_RDONLY);
	if (fd1 < 0)
		perror("ERROR: input file");
	else
	{
		dup2(fd1, fd_tab[0]);
		close(fd1);
	}
	fd2 = open(output, O_CREAT | O_WRONLY, 0777);
	if (fd2 < 0)
		perror("ERROR: output file");
	else
	{
		dup2(fd2, fd_tab[size - 1]);
		close(fd2);
	}	
}
void	ft_set_heredoc(int *fd_tab, char *limit, char *output, int size)
{
	char buf[BUFFER_SIZE];
	int read_ret;
	int	fd_out;

	read_ret = 1;
	while (read_ret)
    {
        write(1, "pipe heredoc> ", 14);
        read_ret = read(0, buf, BUFFER_SIZE);
        buf[read_ret] = '\0';
        if (!(ft_strncmp(buf, limit, ft_strlen(limit))))
            break ;
        write(fd_tab[1], buf, ft_strlen(buf));
    }
    close(fd_tab[1]);
	fd_out = open(output, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd_out < 0)
		perror("ERROR: output file");
	else
	{
		dup2(fd_out, fd_tab[size - 1]);
		close(fd_out);
	}	
}

void	ft_clean(char **str_array, int *fds, int argc)
{
	int	i;
	int	nb_pipe;

	nb_pipe = ((argc - 3) + 1) * 2;
	if (str_array)
	{	i = 0;
		while(*(str_array + i))
		{
			free(*(str_array + i));
			i++;
		}
		free(str_array);
	}
	if (fds)
	{
		i = -1;
		while (++i < nb_pipe)
			close(fds[i]);
		free(fds);
	}
}

void	ft_wait_childs(int nb_child)
{
	int	i;

	i = -1;
	while (++i < nb_child)
		wait(NULL);
}

int	ft_get_nb_child(char *here_doc)
{
	if (!(strncmp(here_doc, "here_doc", ft_strlen("here_doc"))))
		return (1);
	else
		return (0);
}