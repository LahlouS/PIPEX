#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	printf("CEST DE LA FOLIE\n");
	char **paths = ft_split((ft_get_path_line(envp)) + 5, ':');
	int i = 0;
	// while (*(paths + i))
	// {
	// 	printf("path: %s\n", *(paths + i));
	// 	i++;
	// }
	i = 0;
	s_child child_info;

	if (argc >= 5)
	{
		i = 0;
		while (++i < argc)
		{
			ft_setup_child_arg(&child_info, paths, *(argv + i));
			int e = 0;
			while (*((child_info.args) + e))
			{
				printf("%s\n", *((child_info.args) + e));
				e++;
			}
			if (i)
				break ;
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
			return (*(environ + i));
		i++;
	}
	return (NULL);
}

void    ft_setup_child_arg(s_child *child_info, char **paths, char *cmd)
{
	char buf[BUFFER_SIZE];
	int	i;
	int	access_ret;

	i = 0;
	while (1)
	{
		/*ici il faudra rajouter un premier appel a access() afin de voir si *cmd contient deja un PATH valide,
		dans ce cas la je break direct.*/
		ft_cat_cmd_to_path(buf, *(paths + i), cmd, ' ');
		access_ret = access(buf, X_OK);
		if (!(access_ret))
			break ;
		if (!(*(paths + i)))
		{
			break ;
		}
		i++;
	}
	if (!access_ret)
	{
		ft_cat_cmd_to_path(buf, *(paths + i), cmd, '\0');
		child_info->args = ft_split(buf, ' ');
		//printf("\nOK buf: %s\n", buf);
	}
	else
		write(1, "ERROR: command not found\n", 25);
}


