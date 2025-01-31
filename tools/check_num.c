/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:34:15 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/26 18:04:27 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_num(char *s)
{
	while (*s && *s != '=')
	{
		if (*s >= '0' && *s <= '9')
			return (1);
		s++;
	}
	return (0);
}
