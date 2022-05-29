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
		write(fds[5], "SACHASACHASACHASACHASACHA\n", 26);
		i = 1;
		while (++i < (argc - 1))
		{
			if (ft_setup_child(&child_info, paths, *(argv + i), fds))
			{
				printf("--> *(child_info.fd) = %d\n", *(child_info.fd));
				printf("fds[0] = %d\n", fds[0]);
				printf("fds[2] = %d\n", fds[2]);				
				printf("fds[4] = %d\n", fds[4]);
			}
		}
	}
	else
		write(1 ,"ERROR: Invalid Arguments\n", 25);
	return (0);
}
