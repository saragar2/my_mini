#include "../include/minishell.h"

void	manage_fd(t_minishell *minishell, int i)
{
	minishell->before_infile = minishell->infile;
	if (minishell->pipes != 0 && i < minishell->pipes)
	{
		if (minishell->outfile == minishell->pipe_fd[i][1])
			minishell->infile = minishell->pipe_fd[i][0];
		else
			minishell->infile = minishell->outfile;
	}
	if (i == minishell->pipes)
	{
		if (minishell->infile != 0)
			close(minishell->infile);
	}
}

void	ft_set_next_fd(t_minishell *minishell, int i)
{
	manage_fd(minishell, i);
	if (i < minishell->pipes && minishell->pipes != 0)
		minishell->before_outfile = minishell->outfile;
	minishell->outfile = 1;
}

void	init_fork(t_minishell *minishell, int i)
{
	char	*cmd;
	char	**cmd_argv;

	signal(SIGINT, ctrl_c_command);
	signal(SIGQUIT, ctrl_slash_command);
	if (minishell->infile == -1 || minishell->outfile == -1)
		return (minishell->exit_status = 1, minishell->exit = 1, minishell->wait_pid_status = 0, (void)0);
	cmd = get_cmd_in_line(minishell->tokens, i, minishell->pipes);
	if (!cmd)
		return ;
	cmd_argv = ft_split_minishell(cmd);
	if (ft_strncmp(cmd_argv[0], "exit", ft_strlen("exit")) == 0
		|| ft_strncmp(cmd_argv[0], "export", ft_strlen("export")) == 0
		|| ft_strncmp(cmd_argv[0], "unset", ft_strlen("unset")) == 0
		|| ft_strncmp(cmd_argv[0], "cd", ft_strlen("cd")) == 0)
		builtin_execute(minishell, cmd_argv);
	else
	{
		minishell->pid[i] = fork();
		if (minishell->pid[i] < 0)
			return ;
		if (minishell->pid[i] == 0)
			ft_execute_command(minishell, i, minishell->pipes);
	}
	ft_set_next_fd(minishell, i);
	ft_free_double_array(cmd_argv);
}

void	create_forks(t_minishell *minishell)
{
	if (minishell->pipes >= 0)
	{
		minishell->pid = (pid_t *)malloc(sizeof(pid_t) * (minishell->pipes + 1));
		if (!minishell->pid)
			return ;
	}
	else
		return ;
}

void	init_execution(t_minishell *minishell)
{
	int	i;

	i = 0;
	if (minishell->error > 0)
		return (minishell->error = 0, (void)0);
	signal(SIGINT, SIG_IGN);
	create_forks(minishell);
	create_pipes(minishell);
	while (i < minishell->pipes + 1)
	{
		minishell->infile = get_infile(minishell, minishell->infile, i);
		if (i < minishell->pipes)
			pipe_create(minishell, i);
		minishell->outfile = get_outfile(minishell, minishell->outfile, i);
		// printf("infile: %d\noutfile: %d\ni: %d\n", minishell->infile, minishell->outfile, i);
		if (minishell->before_infile != 0)
		{
			// printf("close: %d\n", minishell->before_infile);
			close(minishell->before_infile);
		}
		if (minishell->before_outfile != 1)
		{
			// printf("close: %d\n", minishell->before_outfile);
			close(minishell->before_outfile);
		}
		init_fork(minishell, i);
		if (minishell->exit == 1)
			break ;
		i++;
	}
	// printf("sexyyyy\n");
	free_all(minishell, 0);
}