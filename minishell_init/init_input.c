/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:18 by saragar2          #+#    #+#             */
/*   Updated: 2024/12/03 19:15:03 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		rl_on_new_line();
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

char	*init_input(t_minishell *minishell)
{
	char	*input;

	minishell->exit = 0;
	minishell->wait_pid_status = 1;
	if (get_env_value("PS1", minishell) == NULL)
		input = readline("Minishell$ ");
	else
		input = readline(get_env_value("PS1", minishell));
	if (input == NULL)
		minishell->exit_status = 0;
	if (input != NULL && input[0] != '\0')
		add_history(input);
	return (input);
}
