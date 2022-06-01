/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:48:11 by slahlou           #+#    #+#             */
/*   Updated: 2022/05/31 17:48:15 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(const int argc, char **argv, char **envp)
{
	int		*fds;
	char	**paths;
	int		i;
	t_child	child_info;

	if (argc >= 5)
	{
		paths = ft_split((ft_get_path_line(envp)), ':');
		fds = ft_setup_pipes(argc, argv);
		i = 1 + ft_get_nb_child(*(argv + 1));
		while (++i < (argc - 1))
		{
			if (ft_setup_child(&child_info, paths, *(argv + i), fds))
				ft_give_birth(&child_info);
		}
		ft_wait_childs(i - 2);
		ft_clean(paths, fds, argc - ft_get_nb_child(*(argv + 1)));
	}
	else
		write(1, "ERROR: Invalid Arguments\n", 25);
	return (0);
}

void	ft_give_birth(t_child *child_info)
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

void	ft_clean(char **str_array, int *fds, int argc)
{
	int	i;
	int	nb_pipe;

	nb_pipe = ((argc - 3) + 1) * 2;
	if (str_array)
	{
		i = 0;
		while (*(str_array + i))
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
