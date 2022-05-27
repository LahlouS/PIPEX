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