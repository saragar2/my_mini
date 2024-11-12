/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_with_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:24:59 by saragar2          #+#    #+#             */
/*   Updated: 2024/11/12 19:25:00 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strtrim_with_free(char *str, char *trim)
{
	char	*str_cpy;

	str_cpy = ft_strdup(str);
	free(str);
	str = ft_strtrim(str_cpy, trim);
	free(str_cpy);
	return (str);
}
