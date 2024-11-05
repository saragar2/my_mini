#include "../include/minishell.h"

char	*get_heredoc_line(char *eof)
{
	char	*line;
	char	*line_to_get;

	signal(SIGINT, ctlc_heredoc);
	line = ft_strdup("");
	while (1)
	{
		line_to_get = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line_to_get, eof, ft_strlen(eof)) != 0)
		{
			line = ft_strjoin(line, line_to_get);
			free(line_to_get);
		}
		else
		{
			free(line_to_get);
			break ;
		}
	}
	return (line);
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
	t_token *list;

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
		if (list->infile == 1 || list->heredoc == 1)
		{
			if (infile_fd != 0)
				close(infile_fd);
		}
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
