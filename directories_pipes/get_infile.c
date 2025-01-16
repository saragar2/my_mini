/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:23:11 by saragar2          #+#    #+#             */
/*   Updated: 2025/01/16 17:12:12 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_heredoc_line(char *eof)
{
	t_heredoc	g;

	g.line = NULL;
	if (pipe(g.pipe_fd) == -1)
		return (perror("pipe"), NULL);
	g.pid = fork();
	if (g.pid == -1)
		return (perror("fork"), NULL);
	if (g.pid == 0)
		help_son_process(&g, eof);
	else
	{
		if (help_father_process(&g) == 1)
			return (NULL);
	}
	return (g.line);
}

int	get_heredoc_fd(t_token *list)
{
	int		fd[2];
	char	*here_doc_line;

	if (pipe(fd) < 0)
		return (0);
	else
	{
		here_doc_line = get_heredoc_line(list->str);
		write(fd[1], here_doc_line, ft_strlen(here_doc_line));
		close(fd[1]);
		free(here_doc_line);
		return (fd[0]);
	}
}

int	get_infile_fd(t_token *list)
{
	int	infile_fd;

	infile_fd = open(list->str, O_RDONLY);
	if (infile_fd < 0)
	{
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(list->str, 2);
	}
	return (infile_fd);
}

int	get_infile(t_minishell *minishell, int infile_fd, int pipe_index)
{
	t_token	*list;

	list = *minishell->tokens;
	while ((minishell->pipes) - pipe_index < minishell->pipes)
	{
		while (list && list->type != PIPE)
			list = list->next;
		list = list->next;
		pipe_index--;
	}
	while (list && list->type != PIPE)
	{
		if ((list->infile == 1 || list->heredoc == 1) && (infile_fd != 0))
			close(infile_fd);
		if (list->infile == 1)
			infile_fd = get_infile_fd(list);
		else if (list->heredoc == 1)
			infile_fd = get_heredoc_fd(list);
		list = list->next;
		if (infile_fd < 0)
			return (infile_fd);
	}
	return (infile_fd);
}
