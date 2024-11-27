/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:22:54 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/27 18:43:30 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	change_env_value(char *name, char *value, t_minishell *minishell)
{
	char	*full_name;
	int		i;

	i = 0;
	full_name = ft_strjoin(name, "=");
	while (ft_strncmp(full_name, minishell->env[i], ft_strlen(full_name)) != 0)
		i++;
	free(minishell->env[i]);
	minishell->env[i] = ft_strjoin(full_name, value);
	if (value != NULL)
		free(value);
	return ;
}

static int	has_equal_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*get_env_name(char *str)
{
	char	*name;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != '=')
		len++;
	name = (char *)malloc(sizeof(char) * (len + 1));
	if (!name)
		return (NULL);
	while (i < len)
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

void	new_minishell_env(t_minishell *minishell, char **argv, int argc)
{
	char	*new_str;
	char	*old_str1;
	char	*combination_of_argv;

	old_str1 = ft_strdup(argv[1]);
	if (argc >= 2)
	{
		combination_of_argv = get_comb_of_argv(argc, argv);
		new_str = ft_strjoin(old_str1, combination_of_argv);
		free(combination_of_argv);
	}
	else //------------------------------------esto es necesario?
	{
		free(old_str1);
		new_str = ft_strdup(argv[1]);
	}
	add_new_export_env(new_str, minishell);
}

void	export_builtin(int argc, char **argv, t_minishell *minishell)
{
	int		i;
	char	*env_name;

	// printf("\n\nmira como molo: %d\n-----------------\n", argc);
	i = 0;
	if (argc == 1)
	{
		while (minishell->env[i])
		{
			env_name = get_env_name(minishell->env[i]);
			printf("declare -x %s=\"%s\"\n", env_name,
				get_env_value(env_name, minishell));
			free(env_name);
			i++;
		}
	}

	//-----------------------todo esto está mal planteado porque soy tonta y solo sirve para el primer argv
	
	else if (check_num(argv[1]) == 0 || ft_strncmp("PS1", argv[1], 3) == 0)
	{
		if (has_equal_sign(argv[1]) == 0)
			return ;
		new_minishell_env(minishell, argv, argc);
	}
	else if (check_num(argv[1]) == 1)
	{
		ft_putendl_fd("export: not a valid identifier", STDERR_FILENO);
		return (minishell->exit_status = 1, (void)0);
	}
	minishell->exit_status = 0;
	minishell->wait_pid_status = 0;
}
