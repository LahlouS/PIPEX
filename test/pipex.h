
#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#define WRITE 1
#define READ 0
#define BUFFER_SIZE 200

typedef struct s_child
{
	char **args;
	int *fd;
}   s_child;

char	**ft_split(char const *s, char c);
char    *ft_get_path_line(char **environ);
int		ft_setup_child_arg(s_child *child_info, char **paths, char *cmd);
int		*ft_setup_pipes(int argc, char *infile, char *outfile);
void	ft_set_input_output(int *fd_tab, char *infile, char *outfile, int size);


/*tools*/
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_cat_cmd_to_path(char *buf, char *path, char *cmd, char cmd_sep);

#endif