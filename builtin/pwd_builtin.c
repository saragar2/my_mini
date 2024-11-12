/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:22:57 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:22:58 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	pwd_builtin(int argc, char **argv, t_minishell *minishell)
{
	char	buffer[PATH_MAX];

	(void)argc;
	(void)argv;
	(void)minishell;
	if (getcwd(buffer, sizeof(buffer)) == NULL)
		printf("error\n");
	else
		ft_putendl_fd(buffer, STDOUT_FILENO);
}
