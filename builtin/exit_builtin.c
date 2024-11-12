/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:22:51 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 20:37:49 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_is_num(char *str, t_minishell *minishell)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	else if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return (0);
	ft_atoi(str, &(minishell->atoi_flag));
	if (minishell->atoi_flag == 1)
		return (0);
	return (1);
}

void	exit_builtin(int argc, char **argv, t_minishell *minishell)
{
	minishell->wait_pid_status = 0;
	if (argc == 1)
		return (minishell->exit_status = 0, ft_exit_no_error(EXIT, minishell));
	else if (argc == 2 && ft_is_num(argv[1], minishell) == 1)
	{
		minishell->exit_status = ft_atoi(argv[1], &(minishell->atoi_flag));
		return (ft_exit_no_error(EXIT, minishell));
	}
	else if (argc >= 2 && ft_is_num(argv[1], minishell) == 0)
	{
		minishell->exit_status = 2;
		printf("exit\nexit: %s: numeric argument required\n", argv[1]);
		return (ft_exit_no_error(NULL, minishell));
	}
	else if (argc > 2)
		printf("exit\nexit: too many arguments\n");
	return ;
}
