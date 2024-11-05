#include "../include/minishell.h"

t_token	**ft_create_double_list(void)
{
	t_token	**list_of_tokens;

	list_of_tokens = (t_token **)malloc(sizeof(t_token *));
	if (!list_of_tokens)
		return (NULL);
	*list_of_tokens = NULL;
	return (list_of_tokens);
}

t_token	*ft_lstnew_token(int type, char *str)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->type = type;
	node->next = NULL;
	node->str = str;
	node->infile = 0;
	node->outfile = 0;
	node->cmd = 0;
	node->append = 0;
	node->heredoc = 0;
	return (node);
}

void	ft_lstadd_token_back(t_token **token_list, t_token *new)
{
	t_token	*list;

	list = *token_list;
	if (!(*token_list))
		*token_list = new;
	else
	{
		while (list->next != NULL)
			list = (list)->next;
		list->next = new;
	}
}

char	*get_first_word(t_token *list)
{
	char	*str;
	int		len;
	char	*first_word;
	int		j;

	j = 0;
	len = 0;
	str = list->str;
	while (str[len] && str[len] != ' ' && str[len] != '\t' && str[len] != '\n')
		len++;
	first_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!first_word)
		return (NULL);
	while (j < len)
	{
		first_word[j] = str[j];
		j++;
	}
	first_word[j] = '\0';
	return (first_word);
}

char	*get_after_first_word(t_token *list, char *first_word)
{
	int		len;
	int		i;
	char	*rest_of_word;
	int		j;

	i = 0;
	len = ft_strlen(first_word);
	j = len;
	while (list->str[len])
		len++;
	rest_of_word = (char *)malloc(sizeof(char) * (len - j + 1));
	if (!rest_of_word)
		return (NULL);
	while (j < len)
	{
		rest_of_word[i] = list->str[j];
		i++;
		j++;
	}
	rest_of_word[i] = '\0';
	return (rest_of_word);
}