/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:25:17 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:25:18 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	env_test(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (minishell->env[i])
	{
		printf("%s\n", minishell->env[i]);
		i++;
	}
	printf("\n");
	printf("i: %d\nMinishell->size_of_env: %d\n", i, minishell->size_of_env);
	return ;
}
