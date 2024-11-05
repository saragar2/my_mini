#include "../include/minishell.h"

int	get_append_fd(t_token *list)
{
	int	append_fd;

	append_fd = open(list->str, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (append_fd < 0)
	{
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(list->str, 2);
	}
	return (append_fd);
}

int	get_outfile_fd(t_token *list)
{
	int	outfile_fd;

	outfile_fd = open(list->str, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile_fd < 0)
	{
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(list->str, 2);
	}
	return (outfile_fd);
}

int	get_outfile(t_minishell *minishell, int outfile_fd, int pipe_index)
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
		if (list->outfile == 1 || list->append == 1)
		{
			if (outfile_fd != 1)
				close(outfile_fd);
		}
		if (list->outfile == 1)
			outfile_fd = get_outfile_fd(list);
		else if (list->append == 1)
			outfile_fd = get_append_fd(list);
		list = list->next;
		if (outfile_fd < 0)
			return (outfile_fd);
	}
	return (outfile_fd);
}