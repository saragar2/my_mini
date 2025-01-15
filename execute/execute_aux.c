/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:12:52 by saragar2          #+#    #+#             */
/*   Updated: 2025/01/15 20:18:09 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_auxiliar_pid(t_minishell *minishell, int i)
{
	minishell->pid[i] = fork();
	if (minishell->pid[i] < 0)
		return (-1);
	if (minishell->pid[i] == 0)
		ft_execute_command(minishell, i, minishell->pipes);
	return (0);
}
