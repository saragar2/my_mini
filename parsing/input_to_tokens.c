/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:28 by saragar2          #+#    #+#             */
/*   Updated: 2025/01/15 19:50:21 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_create_token(t_minishell *minishell, int type, int index, int init_str)
{
	char	*str;
	t_token	*new_node;
	int		i;
	int		j;

	j = 0;
	i = init_str;
	if (!(minishell->tokens))
		minishell->tokens = ft_create_double_list();
	str = (char *)malloc(sizeof(char) * (index - init_str + 1));
	if (!str)
		return (-1);
	while (i < index)
	{
		str[j] = minishell->user_input[i];
		i++;
		j++;
	}
	str[j] = '\0';
	new_node = ft_lstnew_token(type, str);
	ft_lstadd_token_back(minishell->tokens, new_node);
	return (index);
}

char	*update_line_with_env_value(char *line, int i, t_minishell *minishell)
{
	int		stay;
	char	**substring;
	int		j;

	j = 0;
	stay = i;
	substring = (char **)malloc(sizeof(char *) * 4);
	if (!substring)
		return (NULL);
	substring[0] = get_line_before_env(line, i);
	while (line[i]
		&& line[i] != '"'
		&& line[i] != '\''
		&& line[i] != ' '
		&& line[i] != '\t'
		&& line[i] != '\n')
		i++;
	substring[1] = get_env(line, stay, i, minishell);
	substring[2] = get_line_after_env(line, i);
	substring[3] = NULL;
	free(line);
	line = get_line_after_env_change(substring, line, i, j);
	ft_free_env_line_array(substring);
	return (line);
}

char	*change_to_env_value(char	*line, t_minishell *minishell)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\0' && line[i] != '\'')
				i++;
			if (!line[i])
				return (line);
		}
		if (line[i] == '$' && (line[i + 1] != ' '
				&& line[i + 1] != '\t' && line[i + 1] != '\n'
				&& line[i + 1] && line[i + 1] != '\"'))
		{
			line = update_line_with_env_value(line, i, minishell);
			if (!line)
				return (NULL);
			i = -1;
		}
		i++;
	}
	return (line);
}

void	input_to_tokens(t_minishell *mini)
{
	int	i;

	i = 0;
	signal(SIGINT, SIG_IGN);
	mini->user_input = change_to_env_value(mini->user_input, mini);
	while (mini->user_input[i])
	{
		while ((mini->user_input[i] == ' '
				|| mini->user_input[i] == '\t'
				|| mini->user_input[i] == '\n')
			&& mini->user_input[i])
			i++;
		if (mini->user_input[i] == '\0')
			return ;
		if (mini->user_input[i] == '<' || mini->user_input[i] == '>')
			i = redirection_token(mini, i);
		else if (mini->user_input[i] == '|')
			i = pipe_token(mini, i);
		else if (mini->user_input[i] == '\''
			|| mini->user_input[i] == '"')
			i = quote_token(mini, i);
		else
			i = text_token(mini, i);
	}
	parse_tokens(mini);
}
