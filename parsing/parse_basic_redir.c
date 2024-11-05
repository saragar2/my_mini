#include "../include/minishell.h"

static void	get_infile_token(t_token *list)
{
	char	*infile;
	char	*after_infile;
	t_token	*new;
	t_token *next_token;

	infile = get_first_word(list->next);
	after_infile = get_after_first_word(list->next, infile);
	next_token = list->next->next;
	free(list->next->str);
	free(list->next);
	new = ft_lstnew_token(TEXT, infile);
	new->infile++;
	list->next = new;
	if (!after_infile)
		new->next = next_token;
	else
	{
		new->next = ft_lstnew_token(TEXT, after_infile);
		new->next->next = next_token;
	}
}

static void	get_outfile_token(t_token *list)
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
	new->outfile++;
	list->next = new;
	if (!after_outfile)
		new->next = next_token;
	else
	{
		new->next = ft_lstnew_token(TEXT, after_outfile);
		new->next->next = next_token;
	}
}

void	parse_redir_input(t_minishell *minishell, t_token *list)
{
	if (!(list->next) || (list->next->type != TEXT && list->next->type != SINGLE_QUOTE && list->next->type != DOUBLE_QUOTE))
	{
		minishell->error++;
		return ;
	}
	else
	{
		if (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE)
			list->next->infile++;
		else
			get_infile_token(list);
	}
}

void	parse_redir_output(t_minishell *minishell, t_token *list)
{
	if (!(list->next) || (list->next->type != TEXT && list->next->type != SINGLE_QUOTE && list->next->type != DOUBLE_QUOTE))
	{
		minishell->error++;
		return ;
	}
	else
	{
		if (list->next->type == SINGLE_QUOTE || list->next->type == DOUBLE_QUOTE)
			list->next->outfile++;
		else
			get_outfile_token(list);
	}
}