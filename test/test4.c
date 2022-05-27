#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char **paths = ft_split((ft_get_path_line(envp)) + 5, ':');
	int i = 0;
	s_child child_info;

	if (argc >= 5)
	{
		i = 0;
		while (++i < argc)
		{
			ft_set_up_child(&child_info, paths, *(argv + i));
		}
	}
	else
		printf("Erreur: Arguments inexploitables\n");
	return (0);
}

char    *ft_get_path_line(char **environ)
{
	int	i;

	i = 0;
	while (*(environ + i))
	{
		if ((ft_strncmp("PATH=", *(environ + i), 5)) == 0)
		{
			return (*(environ + i));
		}
		i++;
	}
	return (NULL);
}

void    ft_set_up_child(s_child *child_info, char **paths, char *cmd)
{
	char *buf[BUFFER_SIZE];

	
}


