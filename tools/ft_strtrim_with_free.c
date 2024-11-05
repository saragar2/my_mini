#include "../include/minishell.h"

char	*ft_strtrim_with_free(char *str, char *trim)
{
	char	*str_cpy;

	str_cpy = ft_strdup(str);
	free(str);
	str = ft_strtrim(str_cpy, trim);
	free(str_cpy);
	return (str);
}