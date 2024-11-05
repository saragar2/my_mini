#include "../include/minishell.h"

void	unset_env(char *str, t_minishell *minishell)
{
	char	**new_env;
	int		len;
	int		i;
	int		j;

	i = -1;
	len = 0;
	j = 0;
	while (minishell->env[len])
		len++;
	new_env = (char **)malloc(sizeof(char *) * len);
	if (!new_env)
		return ;
	while (minishell->env[++i])
	{
		if (ft_strncmp(minishell->env[i], str, ft_strlen(str)) == 0)
			i++;
		if (minishell->env[i] == NULL)
			break ;
		new_env[j] = ft_strdup(minishell->env[i]);
		j++;
	}
	new_env[j] = NULL;
	ft_free_double_array(minishell->env);
	minishell->env = new_env;
}

char	**add_env(char *str, t_minishell *minishell)
{
	int		len;
	char	**new_env;
	int		i;

	i = 0;
	len = double_str_len(minishell->env);
	new_env = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_env)
		return (NULL);
	while (minishell->env[i])
	{
		new_env[i] = ft_strdup(minishell->env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	new_env[i + 1] = NULL;
	ft_free_double_array(minishell->env);
	minishell->env = NULL;
	return (new_env);
}

void	set_env_value(char *str, char *value, t_minishell *minishell)
{
	int		i;
	char	*str_cpy;

	i = 0;
	while (minishell->env[i] && ft_strncmp(minishell->env[i], str, ft_strlen(str)))
		i++;
	if (minishell->env[i] == NULL)
		return ;
	else
	{
		free(minishell->env[i]);
		str_cpy = ft_strjoin(ft_strdup(str), "=");
		minishell->env[i] = ft_strjoin(str_cpy, value);
	}
	return ;
}

char	*get_env_value(char *str, t_minishell *minishell)
{
	int		i;
	char	*value;

	i = 0;
	value = get_env_name(minishell->env[i]);
	while (minishell->env[i] && ft_strncmp(value, str, ft_strlen(str) + 1))
	{
		free(value);
		i++;
		value = get_env_name(minishell->env[i]);
	}
	free(value);
	if (minishell->env[i] == NULL)
		return (NULL);
	else
	{
		value = minishell->env[i];
		while (*value != '=')
			value++;
		value++;
	}
	return (value);
}

void	sum_one_to_shlvl(t_minishell *minishell)
{
	char	*shlvl;
	int		shlvl_num;
	char	*shlvl_num_array;

	shlvl = get_env_value("SHLVL", minishell);
	if (shlvl == NULL)
		return ;
	shlvl_num = ft_atoi(shlvl) + 1;
	shlvl_num_array = ft_itoa(shlvl_num);
	set_env_value("SHLVL", shlvl_num_array, minishell);
	free(shlvl_num_array);
}