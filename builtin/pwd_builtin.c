#include "../include/minishell.h"

void	pwd_builtin(int argc, char **argv, t_minishell *minishell)
{
	char	buffer[PATH_MAX];

	(void)argc;
	(void)argv;
	(void)minishell;
	if (getcwd(buffer, sizeof(buffer)) == NULL)
	{
		printf("error\n");
	}
	else
		ft_putendl_fd(buffer, STDOUT_FILENO);
}