/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:23:17 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:23:18 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pipe_write_dup(t_minishell *minishell, int i)
{
	if (minishell->pipes != 0 && i < minishell->pipes)
	{
		dup2(minishell->outfile, STDOUT_FILENO);
		if (minishell->outfile == minishell->pipe_fd[i][1])
		{
			close(minishell->pipe_fd[i][0]);
			close(minishell->pipe_fd[i][1]);
		}
		else
			close(minishell->outfile);
	}
	else if (minishell->outfile != 1)
	{
		dup2(minishell->outfile, STDOUT_FILENO);
		close(minishell->outfile);
	}
}

void	pipe_read_dup(t_minishell *minishell, int i)
{
	if (i != 0)
	{
		dup2(minishell->infile, STDIN_FILENO);
		if (minishell->infile == minishell->pipe_fd[i - 1][0])
		{
			close(minishell->pipe_fd[i - 1][1]);
			close(minishell->pipe_fd[i - 1][0]);
		}
		else
			close(minishell->infile);
	}
	else if (minishell->infile != 0)
	{
		dup2(minishell->infile, STDIN_FILENO);
		close(minishell->infile);
	}
}

void	pipe_create(t_minishell *minishell, int i)
{
	if (pipe(minishell->pipe_fd[i]) < 0)
		return ;
	minishell->outfile = minishell->pipe_fd[i][1];
}

void	create_pipes(t_minishell *minishell)
{
	int	i;

	i = 0;
	if (minishell->pipes > 0)
	{
		minishell->pipe_fd = (int **)malloc(sizeof(int *) * minishell->pipes);
		if (!minishell->pipe_fd)
			return ;
		while (i < minishell->pipes)
		{
			minishell->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
			if (!minishell->pipe_fd[i])
				return ;
			minishell->pipe_fd[i][0] = -1;
			minishell->pipe_fd[i][1] = -1;
			i++;
		}
	}
}
