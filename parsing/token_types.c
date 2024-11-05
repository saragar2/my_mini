#include "../include/minishell.h"

int		redirection_token(t_minishell *minishell, int i)
{
	char	*line;
	int		stay;

	stay = i;
	line = minishell->user_input;
	if (line[i] == '<')
	{
		if (line[i] == '<' && line[i + 1] == '<')
			return (ft_create_token(minishell, REDIR_HEREDOC, i + 2, stay));
		else
			return (ft_create_token(minishell, REDIR_INPUT, i + 1, stay));
	}
	else
	{
		if (line[i] == '>' && line[i + 1] == '>')
			return (ft_create_token(minishell, REDIR_APPEND, i + 2, stay));
		else
			return (ft_create_token(minishell, REDIR_OUTPUT, i + 1, stay));
	}
}

int		pipe_token(t_minishell *minishell, int i)
{
	minishell->pipes++;
	return (ft_create_token(minishell, PIPE, i + 1, i));
}

int		quote_token(t_minishell *minishell, int i)
{
	char	*line;
	int		stay;

	stay = i;
	line = minishell->user_input;
	if (line[i] == '\'')
	{
		i++;
		while (line[i] != '\'' && line[i])
			i++;
		if (!line[i])
			return (i);
		return (ft_create_token(minishell, SINGLE_QUOTE, i + 1, stay));
	}
	else
	{
		i++;
		while (line[i] != '"' && line[i])
			i++;
		if (!line[i])
			return (i);
		return (ft_create_token(minishell, DOUBLE_QUOTE, i + 1, stay));
	}
}

int		text_token(t_minishell *minishell, int i)
{
	char	*line;
	int		stay;

	stay = i;
	line = minishell->user_input;
	while (line[i] != '<' && line[i] != '>' && line[i] != '|' && line[i] != '\'' && line[i] != '"')
	{
		if (!line[i])
			break ;
		i++;
	}
	return (ft_create_token(minishell, TEXT, i, stay));
}
