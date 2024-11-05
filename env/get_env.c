#include "../include/minishell.h"

char	*get_value(char *str)
{
	int		i;
	char	*value;

	i = 0;
	while (*str != '=')
		str++;
	str++;
	while (str[i])
		i++;
	if (i == 0)
		return (ft_strdup(""));
	value = (char *)malloc(sizeof(char) * (i + 1));
	if (!value)
		return (NULL);
	i = -1;
	while (str[++i])
		value[i] = str[i];
	value[i] = '\0';
	return (value);
}

char	**new_list_of_env(char **environ, t_minishell *minishell)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = (char **)malloc(sizeof(char *) * (minishell->size_of_env + 1));
	if (!new_env)
		return (NULL);
	while (i < minishell->size_of_env)
	{
		if (!(new_env[i] = ft_strdup(environ[i])))
		{
			ft_free_double_array_until_length(new_env, i);
			return (NULL);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

void	get_list_of_env(char **environ, t_minishell *minishell)
{
	minishell->size_of_env = double_str_len(environ);
	minishell->env = new_list_of_env(environ, minishell);
}

void	add_new_export_env(char *new_str, t_minishell *minishell)
{
	char	*env_name;

	env_name = get_env_name(new_str);
	if (get_env_value(env_name, minishell) != NULL)
	{
		change_env_value(env_name, get_value(new_str), minishell);
		env_name = NULL;
		free(new_str);
	}
	else
	{
		minishell->env = add_env(new_str, minishell);
		free(new_str);
	}
	if (env_name)
		free(env_name);
}