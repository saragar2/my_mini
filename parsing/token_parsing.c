/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:41 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:24:42 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	remove_redir_tokens(t_token **tokens)
{
	t_token	*list;

	list = *tokens;
	while (list)
	{
		if (list->type == REDIR_APPEND || list->type == REDIR_HEREDOC
			|| list->type == REDIR_INPUT || list->type == REDIR_OUTPUT)
		{
			del_token(list, tokens);
			list = *tokens;
		}
		else
			list = list->next;
	}
	list = *tokens;
	while (list->next)
	{
		if (list->cmd == 1 && list->next->cmd == 1)
		{
			join_tokens(list, list->next, tokens);
			list = *tokens;
		}
		else
			list = list->next;
	}
}

int	check_all_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

static int	check_quotes(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (len < 2)
		return (0);
	if (str[i] == '\"')
	{
		i++;
		while (str[i] != '\"'
			&& (str[i] == ' '
				|| str[i] == '\t'
				|| str[i] == '\n'))
			i++;
		if (str[i] == '\"')
			return (1);
	}
	else if (str[i] == '\'')
	{
		i++;
		while (str[i] != '\''
			&& (str[i] == ' '
				|| str[i] == '\t'
				|| str[i] == '\n'))
			i++;
		if (str[i] == '\'')
			return (1);
	}
	return (0);
}

int	no_spaces_before_or_after_tokens(t_minishell *minishell, t_token **tokens)
{
	t_token	*list;
	char	*str_cpy;

	list = *tokens;
	while (list)
	{
		str_cpy = list->str;
		if (check_all_spaces(list->str))
		{
			del_token(list, tokens);
			list = *tokens;
		}
		else
		{
			if (check_quotes(list->str))
				return (no_exit_free(list->str, NOT_CMD, minishell), 1);
			list->str = ft_strtrim(str_cpy, " \tn");
			free(str_cpy);
			list = list->next;
		}
	}
	remove_redir_tokens(tokens);
	if (minishell->error == 1)
		return (minishell->error = 0, free_all(minishell, 0), 1);
	return (0);
}

void	parse_tokens(t_minishell *minishell)
{
	t_token	*list;

	if (!minishell->tokens)
		return (free_all(minishell, 0), (void)0);
	list = *minishell->tokens;
	while (list)
	{
		if (list->type == REDIR_INPUT)
			parse_redir_input(minishell, list);
		else if (list->type == REDIR_OUTPUT)
			parse_redir_output(minishell, list);
		else if (list->type == REDIR_APPEND)
			parse_redir_append(minishell, list);
		else if (list->type == REDIR_HEREDOC)
			parse_redir_heredoc(minishell, list);
		else if (list->type == PIPE)
			parse_pipe(minishell, list);
		else if (list->type == TEXT)
			parse_text(list);
		else
			parse_quotes(list);
		list = list->next;
	}
	if (no_spaces_before_or_after_tokens(minishell, minishell->tokens) == 0)
		init_execution(minishell);
}
