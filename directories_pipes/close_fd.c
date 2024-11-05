#include "../include/minishell.h"

void	ft_close_free_pipefd(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (i < minishell->pipes)
	{
		if (minishell->pipe_fd[i][1] < 0)
			close(minishell->pipe_fd[i][1]);
		if (minishell->pipe_fd[i][0] < 0)
			close(minishell->pipe_fd[i][0]);
		free(minishell->pipe_fd[i]);
		i++;
	}
}

void	close_file_descriptors(t_minishell *minishell)
{
	if (minishell->pipe_fd)
		ft_close_free_pipefd(minishell);
	if (minishell->infile != 0)
		close(minishell->infile);
	if (minishell->before_infile != 0)
		close(minishell->before_infile);
	if (minishell->outfile != 1)
		close(minishell->outfile);
	if (minishell->before_outfile != 1)
		close(minishell->before_outfile);
	free_pids(minishell->pid);
	minishell->pipes = 0;
	minishell->pid = 0;
	minishell->infile = 0;
	minishell->outfile = 1;
	minishell->before_infile = 0;
	minishell->before_outfile = 1;
	if (minishell->pipe_fd)
		free(minishell->pipe_fd);
	minishell->pid = NULL;
	minishell->pipe_fd = NULL;
}