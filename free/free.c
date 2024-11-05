#include "../include/minishell.h"

void	no_exit_free(char *str1, char *str2, t_minishell *minishell)
{
	char	*str_trim;

	str_trim = ft_strtrim(str1, "\'\"");
	ft_putstr_fd(str_trim, STDERR_FILENO);
	free(str_trim);
	ft_putendl_fd(str2, STDERR_FILENO);
	minishell->wait_pid_status = 0;
	minishell->exit_status = 127;
	free_all(minishell, 0);
}

void	free_pids(pid_t *pid)
{
	if (pid != NULL)
	{
		free((void *)&pid[0]);
	}
}

void	free_all(t_minishell *minishell, int is_exit)
{
	int	i;
	int	status;

	status = 0;
	i = -1;
	if (minishell->pid)
	{
		while (++i < minishell->pipes + 1)
			waitpid(minishell->pid[i], &status, 0);
	}
	if (minishell->wait_pid_status == 1)
		minishell->exit_status = WEXITSTATUS(status);
	close_file_descriptors(minishell);
	if (minishell->tokens)
		free_tokens(minishell);
	if (is_exit == 1)
	{
		if (minishell->env)
			ft_free_double_array(minishell->env);
		rl_clear_history();
	}
}
