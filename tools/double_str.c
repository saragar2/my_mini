#include "../include/minishell.h"

int	double_str_len(char **double_array)
{
	int	i;

	i = 0;
	while (double_array[i])
	{
		i++;
	}
	return (i);
}

void	ft_free_double_array_until_length(char **d_array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(d_array[i]);
		i++;
	}
	free(d_array);
}

void	ft_free_double_array(char **double_array)
{
	int	i;

	i = 0;
	while (double_array[i])
	{
		free(double_array[i]);
		i++;
	}
	free(double_array);
}