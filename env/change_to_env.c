#include "../include/minishell.h"

char	*get_line_before_env(char *line, int len)
{
	int		i;
	char	*str1;

	if (len < 1)
		return (NULL);
	str1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!str1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str1[i] = line[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	*get_env(char *line, int stay, int i, t_minishell *minishell)
{
	char	*str2;
	int		j;
	char	*strcpy;

	j = 0;
	if (i - stay <= 1)
		return (NULL);
	str2 = (char *)malloc(sizeof(char) * (i - stay));
	if (!str2)
		return (NULL);
	while (++stay < i)
	{
		str2[j] = line[stay];
		j++;
	}
	str2[j] = '\0';
	strcpy = ft_strdup(str2);
	free(str2);
	if (ft_strncmp(strcpy, "?", 2) == 0)
		str2 = ft_itoa(minishell->exit_status);
	else
		str2 = ft_strdup(get_env_value(strcpy, minishell));
	free(strcpy);
	return (str2);
}

char	*get_line_after_env(char *line, int i)
{
	int		j;
	char	*str3;

	if (!line[i])
		return (NULL);
	str3 = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str3)
		return (NULL);
	j = 0;
	while (line[i])
	{
		str3[j] = line[i];
		j++;
		i++;
	}
	str3[j] = '\0';
	return (str3);
}

char	*get_line_after_env_change(char **substring, char *line, int i, int j)
{
	int	k;

	k = 0;
	i = 0;
	if (!substring[0] && !substring[1] && !substring[2])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen(substring[0]) + ft_strlen(substring[1]) + ft_strlen(substring[2]) + 1));
	if (!line)
		return (NULL);
	while (k < 3)
	{
		j = -1;
		if (substring[k] != NULL)
		{
			while (substring[k][++j])
			{
				line[i] = substring[k][j];
				i++;
			}
		}
		k++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_free_env_line_array(char **substring)
{
	if (substring)
	{
		if (substring[0])
			free(substring[0]);
		if (substring[1])
			free(substring[1]);
		if (substring[2])
			free(substring[2]);
		free(substring);
	}
	return ;
}