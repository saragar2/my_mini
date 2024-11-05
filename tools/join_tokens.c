#include "../include/minishell.h"

static void	init_new_cmd(t_token *cmd)
{
	cmd->append = 0;
	cmd->cmd = 1;
	cmd->infile = 0;
	cmd->heredoc = 0;
	cmd->outfile = 0;
	cmd->type = TEXT;
}

static char	*get_content(char *str1, char *str2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = -1;
	while (str1[++j])
	{
		str[i] = str1[j];
		i++;
	}
	j = -1;
	str[i] = ' ';
	while (str2[++j])
	{
		i++;
		str[i] = str2[j];
	}
	str[i + 1] = '\0';
	return (str);
}

void	ft_free_two_tokens(t_token *cmd1, t_token *cmd2)
{
	free(cmd1->str);
	free(cmd2->str);
	free(cmd1);
	free(cmd2);
}

void	join_tokens(t_token *cmd1, t_token *cmd2, t_token **tokens)
{
	t_token *new_cmd;
	t_token *list;

	new_cmd = (t_token *)malloc(sizeof(t_token));
	if (!new_cmd)
		return ;
	new_cmd->str = get_content(cmd1->str, cmd2->str);
	init_new_cmd(new_cmd);
	list = *tokens;
	if (list == cmd1)
	{
		*tokens = new_cmd;
		new_cmd->next = cmd2->next;
	}
	else
	{
		while (list->next != cmd1)
			list = list->next;
		list->next = new_cmd;
		new_cmd->next = cmd2->next;
	}
	ft_free_two_tokens(cmd1, cmd2);
}