/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:22:47 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:22:48 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env_builtin(int argc, char **argv, t_minishell *minishell)
{
	int	i;

	i = 0;
	if (!minishell->env)
		return ;
	if (argc != 1)
	{
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putendl_fd("\': No such file or directory", STDERR_FILENO);
		minishell->wait_pid_status = 0;
		minishell->exit_status = 127;
	}
	else
	{
		while (minishell->env[i])
		{
			ft_putendl_fd(minishell->env[i], STDOUT_FILENO);
			i++;
		}
	}
	return ;
}
