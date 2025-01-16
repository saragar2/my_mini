/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:59:47 by saragar2          #+#    #+#             */
/*   Updated: 2025/01/16 17:13:20 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	help_son_process(t_heredoc *g, char *eof)
{
	signal(SIGINT, ctlc_heredoc);
	close(g->pipe_fd[0]);
	while (1)
	{
		g->line_to_get = get_next_line(STDIN_FILENO);
		if (!g->line_to_get)
		{
			close(g->pipe_fd[1]);
			exit(1);
		}
		if (ft_strncmp(g->line_to_get, eof, ft_strlen(eof)) != 0
			|| (ft_strlen(g->line_to_get) - 1) != ft_strlen(eof))
		{
			write(g->pipe_fd[1], g->line_to_get, ft_strlen(g->line_to_get));
			write(g->pipe_fd[1], "\n", 1);
			free(g->line_to_get);
		}
		else
		{
			free(g->line_to_get);
			break ;
		}
	}
	close(g->pipe_fd[1]);
	exit(0);
}

int	help_father_process(t_heredoc *g)
{
	close(g->pipe_fd[1]);
	g->line = ft_strdup("");
	g->bytes_read = read(g->pipe_fd[0], g->buffer, sizeof(g->buffer) - 1);
	while (g->bytes_read > 0)
	{
		g->buffer[g->bytes_read] = '\0';
		g->temp = g->line;
		g->line = ft_safe_strjoin(g->line, g->buffer);
		free(g->temp);
		if (!g->line)
			return (close(g->pipe_fd[0]), 1);
		g->bytes_read = read(g->pipe_fd[0], g->buffer, sizeof(g->buffer) - 1);
	}
	close(g->pipe_fd[0]);
	waitpid(g->pid, &g->status, 0);
	if (WIFSIGNALED(g->status) && WTERMSIG(g->status) == SIGINT)
		return (free(g->line), 1);
	return (0);
}
