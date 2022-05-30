#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int *fds;
	char **paths;
	int i;
	s_child child_info;

	if (argc >= 5)
	{
		paths = ft_split((ft_get_path_line(envp)) + 5, ':'); //tableau avec tous les chemins possibles
		fds = ft_setup_pipes(argc, *(argv + 1), *(argv + (argc - 1))); // pipes en fonction du nombres d'arguments + dup infile et outfile
		i = 1;
		while (++i < (argc - 1))
		{
			if (ft_setup_child(&child_info, paths, *(argv + i), fds)) //trouve le bon path et le set dans la struct + donne l'adresse du fd que le child aura besoin 
				ft_give_birth(&child_info);
		}
		ft_wait_childs(i - 2);
		ft_clean(paths, fds);
		//free(fds); tu dois encore free fds, paths (pour ca transforme ta fonction ft_clean_child afin serve 
		//pour tout les tableaux de chaine), et faire la fonction qui close tout tes fd
		//tu dois aussi fair ta fonction qui boucle les waits par rapport au nombre de childs
		//puis tu dois bien tout securiser!!!
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
		ft_clean(child_info->args, NULL);
}