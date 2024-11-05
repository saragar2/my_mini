#include "../include/minishell.h"

void	echo_builtin(int argc, char **argv, t_minishell *minishell)
{
	int	new_line;
	int	i;

	i = 1;
	new_line = 1;
	if (argc == 1)
		return (ft_putchar_fd('\n', STDOUT_FILENO), minishell->exit_status = 0, (void)0);
	else if (argc == 2 && ft_strncmp(argv[1], "-n", ft_strlen("-n")) == 0)
		return ;
	if (ft_strncmp(argv[1], "-n", ft_strlen("-n")) == 0)
	{
		new_line = 0;
		i++;
	}
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (new_line == 1)
		ft_putchar_fd('\n', STDOUT_FILENO);
	minishell->exit_status = 0;
}