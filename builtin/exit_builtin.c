#include "../include/minishell.h"

static int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		else
			i++;
	}
	return (1);
}

void	exit_builtin(int argc, char **argv, t_minishell *minishell)
{
	minishell->wait_pid_status = 0;
	if (argc == 1)
		return (minishell->exit_status = 0, ft_exit_no_error(EXIT, minishell));
	else if (argc == 2 && ft_is_num(argv[1]) == 1)
	{
		minishell->exit_status = ft_atoi(argv[1]);
		return (ft_exit_no_error(EXIT, minishell));
	}
	else if (argc >= 2 && ft_is_num(argv[1]) == 0)
	{
		minishell->exit_status = 2;
		printf("exit\nexit: %s: numeric argument required\n", argv[1]);
		return (ft_exit_no_error(NULL, minishell));
	}
	else if (argc > 2)
		printf("exit\nexit: too many arguments\n");
	return ;
}