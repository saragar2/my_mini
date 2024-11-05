#include "../include/minishell.h"

char	*get_comb_of_argv(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*str_cpy;

	i = 2;
	str = ft_strdup("");
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		if (i + 1 < argc)
			str = ft_strjoin(str, " ");
		i++;
	}
	str_cpy = ft_strdup(str);
	free(str);
	str = ft_strtrim(str_cpy, "\"\'");
	free(str_cpy);
	return (str);
}