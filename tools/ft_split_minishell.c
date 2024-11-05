#include "../include/minishell.h"

static char *get_str(char *str, int	i)
{
	int		length;
	char	*s_return;
	int		j;
	int		total_length;

	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	length = i;
	while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
		i++;
	s_return = (char *)malloc(sizeof(char) * (i - length + 1));
	if (!s_return)
		return (NULL);
	total_length = i - length;
	while (j < total_length)
	{
		s_return[j] = str[length];
		length++;
		j++;
	}
	s_return[j] = '\0';
	return (s_return);
}

static char	*search_str(char *str, int word_index)
{
	int	count_words;
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	count_words = 1;
	while (count_words < word_index + 1)
	{
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (str[i] == '\0')
			return (NULL);
		count_words++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
	}
	return (get_str(str, i));
}

static int	get_words(char *str)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] == '\0')
			break ;
		words++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (words);
}

static void	free_double_str(char **double_str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(double_str[i]);
		i++;
	}
	free(double_str);
}

char	**ft_split_minishell(char *str)
{
	int		words;
	char	**double_str;
	int		i;

	i = -1;
	words = get_words(str);
	double_str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!double_str)
		return (NULL);
	while (++i < words)
	{
		double_str[i] = search_str(str, i);
		if (!double_str[i])
			free_double_str(double_str, i);
	}
	double_str[i] = NULL;
	return (double_str);
}