#include "../include/minishell.h"

void	del_token(t_token *to_del, t_token **list)
{
	t_token *list_cpy;

	list_cpy = *list;
	if (list_cpy == to_del)
	{
		list_cpy = list_cpy->next;
		*list = list_cpy;
	}
	else
	{
		while (list_cpy->next && (list_cpy->next != to_del))
			list_cpy = list_cpy->next;
		if (!list_cpy->next)
			return ;
		list_cpy->next = to_del->next;
	}
	to_del->next = NULL;
	free(to_del->str);
	free(to_del);
}

void	free_tokens(t_minishell *minishell)
{
	t_token *list;
	t_token	*list_plus_one;

	list = *minishell->tokens;
	while (list != NULL)
	{
		list_plus_one = list->next;
		free(list->str);
		free(list);
		list = list_plus_one;
	}
	free(minishell->tokens);
	minishell->tokens = NULL;
}