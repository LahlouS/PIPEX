/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:48:47 by slahlou           #+#    #+#             */
/*   Updated: 2022/05/31 17:48:51 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	ft_cat_cmd_to_path(char *buf, char *path, char *cmd, char cmd_sep)
{
	int	i;

	i = 0;
	while (path && *path)
	{
		buf[i] = *path;
		i++;
		path++;
	}
	if (path != NULL)
	{
		buf[i] = '/';
		i++;
	}
	while (*cmd != cmd_sep && *cmd)
	{
		buf[i] = *cmd;
		i++;
		cmd++;
	}
	buf[i] = '\0';
}

char	*ft_get_path_line(char **environ)
{
	int	i;

	i = 0;
	while (environ && *(environ + i))
	{
		if ((ft_strncmp("PATH=", *(environ + i), 5)) == 0)
			return (*(environ + i));
		i++;
	}
	return (NULL);
}

int	ft_setup_child(t_child *child_info, char **paths, char *cmd, int *fd_tab)
{
	char		buf[BUFFER_SIZE];
	int			i;
	int			access_ret;
	static int	index = 0;

	i = 0;
	while (1)
	{
		ft_cat_cmd_to_path(buf, *(paths + i), cmd, ' ');
		access_ret = access(buf, X_OK);
		if (!(access_ret) || !*(paths + i))
			break ;
		i++;
	}
	if (!access_ret)
	{
		ft_cat_cmd_to_path(buf, *(paths + i), cmd, '\0');
		child_info->args = ft_split(buf, ' ');
		child_info->fd = &fd_tab[index];
		index += 2;
		return (1);
	}
	write(1, "ERROR: command not found\n", 25);
	index += 2;
	return (0);
}
