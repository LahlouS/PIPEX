#include "pipex.h"

int main(int argc, char **argv, char **envp)
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
			if (ft_setup_child_arg(&child_info, paths, *(argv + i)))

		}
	}
	else
		write(1 ,"ERROR: Invalid Arguments\n", 25);
	return (0);
}


