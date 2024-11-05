#include "../include/minishell.h"

void	init_minishell(t_minishell *minishell, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	minishell->exit = 0;
	minishell->exit_status = 0;
	minishell->user_input = NULL;
	minishell->tokens = NULL;
	minishell->pipes = 0;
	minishell->error = 0;
	minishell->infile = 0;
	minishell->outfile = 1;
	minishell->wait_pid_status = 1;
	minishell->pipe_fd = NULL;
	minishell->pid = NULL;
	minishell->before_infile = 0;
	minishell->before_outfile = 1;
}

int	main(int argc, char *argv[], char **env)
{
	t_minishell	minishell;

	signal(SIGQUIT, SIG_IGN);
	init_minishell(&minishell, argc, argv);
	get_list_of_env(env, &minishell);
	sum_one_to_shlvl(&minishell);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, ctrl_c);
		minishell.user_input = init_input(&minishell);
		if (minishell.user_input == NULL)
			ft_exit_no_error(EXIT, &minishell);
		if (is_valid_input(minishell.user_input))
			input_to_tokens(&minishell);
		free(minishell.user_input);
	}
	free_all(&minishell, 1);
	return (0);
}