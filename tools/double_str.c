/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:51 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:24:52 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	double_str_len(char **double_array)
{
	int	i;

	i = 0;
	while (double_array[i])
	{
		i++;
	}
	return (i);
}

void	ft_free_double_array_until_length(char **d_array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(d_array[i]);
		i++;
	}
	free(d_array);
}

void	ft_free_double_array(char **double_array)
{
	int	i;

	i = 0;
	while (double_array[i])
	{
		free(double_array[i]);
		i++;
	}
	free(double_array);
}
