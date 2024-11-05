/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:14:54 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 17:16:21 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	str = (void *)malloc (count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	int *str;
	str = calloc(16, 4);
	int *str1;
	str1 = ft_calloc(16, 4);
	return (0);
}
*/
