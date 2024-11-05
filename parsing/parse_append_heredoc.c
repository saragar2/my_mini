#include "../include/minishell.h"

static void	get_heredoc_token(t_token *list)
{
	char	*eof;
	char	*after_eof;
	t_token	*new;
	t_token *next_token;

	eof = get_first_word(list->next);
	after_eof = get_after_first_word(list->next, eof);
	next_token = list->next->next;
	free(list->next->str);
	free(list->next);
	new = ft_lstnew_token(TEXT, eof);
	new->heredoc++;
	list->next = new;
	if (!after_eof)
		new->next = next_token;
	else
	{
		new->next = ft_lstnew_token(TEXT, after_eof);
		new->next->next = next_token;
	}
}

static void	get_append_token(t_token *list)
{
	char	*outfile;
	char	*after_outfile;
	t_token	*new;
	t_token *next_token;

	outfile = get_first_word(list->next);
	after_outfile = get_after_first_word(list->next, outfile);
	next_token = list->next->next;
	free(list->next->str);
	free(list->next);
	new = ft_lstnew_token(TEXT, outfile);
	new->append++;
	list->next = new;
	if (!after_outfile)
		new->next = next_token;
	else
	{
		new->next = ft_lstnew_token(TEXT, after_outfile);
		new->next->next = next_token;
	}
}

void	parse_redir_append(t_minishell *minishell, t_token *list)
{
	if (!(list->next) || (list->next->type != TEXT && list->next->type != SINGLE_QUOTE && list->next->type != DOUBLE_QUOTE))
	{
		minishell->error++;
		return ;
	}
	else
	{
		if (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE)
			list->next->append++;
		else
			get_append_token(list);
	}
}

void	parse_redir_heredoc(t_minishell *minishell, t_token *list)
{
	if (!(list->next) || (list->next->type != TEXT && list->next->type != SINGLE_QUOTE && list->next->type != DOUBLE_QUOTE))
	{
		minishell->error++;
		return ;
	}
	else
	{
		if (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE)
			list->next->heredoc++;
		else
			get_heredoc_token(list);
	}
}