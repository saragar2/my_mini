#include "../include/minishell.h"

static int	ft_words_for_awk(char *line)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\n' || line[i] == '\t'))
			i++;
		if (!line[i])
			return (words);
		words++;
		if (words == 2)
			return (words);
		while (line[i] && (line[i] != ' ' && line[i] != '\n' && line[i] != '\t'))
			i++;
	}
	return (words);
}

char	**ft_split_for_awk(char *line)
{
	int		words;
	char	**argv;

	words = ft_words_for_awk(line);
	argv = (char **)malloc(sizeof(char *) * (words + 1));
	if (!argv)
		return (NULL);
	argv[0] = ft_strdup("awk");
	if (!argv[0])
		return (free(argv), NULL);
	if (words == 2)
	{
		line = line + 3;
		argv[1] = ft_strdup(line);
		if (!argv[1])
			return (free(argv[0]), free(argv), NULL);
		argv[1] = ft_strtrim(argv[1], " \t\n\'");
	}
	argv[words] = NULL;
	return (argv);
}