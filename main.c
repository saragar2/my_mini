#include "include/minishell.h"

void	env_test(t_minishell *minishell)
{
	int	i = 0;
	while (minishell->env[i]) {
		printf("%s\n", minishell->env[i]);
		i++;
	}
	printf("\n");
	printf("i: %d\nMinishell->size_of_env: %d\n", i, minishell->size_of_env);

	return ;
}