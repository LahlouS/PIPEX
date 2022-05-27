
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
#define BUFFER_SIZE 500

typedef struct s_child
{
    char **args;
    int fd[2];
}   s_child;

char	**ft_split(char const *s, char c);
char    *ft_get_path_line(char **environ);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_set_up_child(s_child *child_info, char **paths, char *cmd);

#endif