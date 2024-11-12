/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:23:54 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:23:55 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit_error(char *str, t_minishell *minishell)
{
	ft_putendl_fd(str, STDERR_FILENO);
	free_all(minishell, 1);
	exit(minishell->exit_status);
}

void	ft_exit_no_error(char *str, t_minishell *minishell)
{
	if (str != NULL)
		ft_putendl_fd(str, STDOUT_FILENO);
	free_all(minishell, 1);
	exit(minishell->exit_status);
}
