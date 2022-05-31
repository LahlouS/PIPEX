#include "pipex.h"

int main(const int argc, char **argv, char **envp)
{
	int *fds;
	char **paths;
	int i;
	s_child child_info;

	if (argc >= 5)
	{
		paths = ft_split((ft_get_path_line(envp)) + 5, ':');
		fds = ft_setup_pipes(argc, *(argv + 1), *(argv + (argc - 1)));
		i = 1;
		while (++i < (argc - 1))
		{
			if (ft_setup_child(&child_info, paths, *(argv + i), fds))
				ft_give_birth(&child_info);
		}
		ft_wait_childs(i - 2);
		ft_clean(paths, fds, argc);
	}
	else
		write(1 ,"ERROR: Invalid Arguments\n", 25);
	return (0);
}

void	ft_give_birth(s_child *child_info)
{
	int	pid;

    close((child_info->fd)[1]);
	pid = fork();
	if (pid < 0)
	{
		perror("Forking error");
		exit (1);
	}
	else if (!pid)
	{
		dup2((child_info->fd)[0], 0);
    	close((child_info->fd)[0]);
    	close((child_info->fd)[1]);
    	dup2((child_info->fd)[3], 1);
    	close((child_info->fd)[3]);
    	if (execve(*(child_info->args), child_info->args, NULL) < 0)
    	{
            perror("Execve function: error encountered");
            exit(1);
        }
	}
	else 
		ft_clean(child_info->args, NULL, 0);
}