/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:38 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:24:39 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parse_pipe(t_minishell *minishell, t_token *list)
{
	t_token	*list_init;

	list_init = *minishell->tokens;
	while (list_init->next != list)
		list_init = list_init->next;
	if (!(list_init)
		|| (list_init->type != TEXT
			&& list_init->type != SINGLE_QUOTE
			&& list_init->type != DOUBLE_QUOTE))
		minishell->error++;
	if (!(list->next) || (list_init->type == PIPE))
	{
		if (minishell->error == 0)
			minishell->error = 1;
	}
	return ;
}

void	parse_text(t_token *list)
{
	if (list->infile == 0
		&& list->outfile == 0
		&& list->append == 0
		&& list->heredoc == 0)
		list->cmd++;
	else
		return ;
}

void	parse_quotes(t_token *list)
{
	if (list->infile == 0 && list->outfile == 0)
		list->cmd++;
	else
		return ;
}
