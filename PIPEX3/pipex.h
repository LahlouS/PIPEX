/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahlou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:48:34 by slahlou           #+#    #+#             */
/*   Updated: 2022/05/31 17:48:37 by slahlou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>

# define BUFFER_SIZE 500

typedef struct s_child
{
	char	**args;
	int		*fd;
}	t_child;

char	**ft_split(char const *s, char c);
char	*ft_get_path_line(char **environ);
int		ft_setup_child(t_child *child_info, \
char **paths, char *cmd, int *fd_tab);
int		*ft_setup_pipes(int argc, char **argv);
int		ft_get_nb_child(char *here_doc);
void	ft_set_input_output(int *fd_tab, char *input, char *output, int size);
void	ft_set_heredoc(int *fd_tab, char *limit, char *output, int size);
void	ft_give_birth(t_child *child_info);
void	ft_clean(char **str_array, int *fds, int argc);
void	ft_wait_childs(int nb_child);
/*tools*/
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_cat_cmd_to_path(char *buf, char *path, char *cmd, char cmd_sep);
#endif
