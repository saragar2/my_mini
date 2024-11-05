/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:59:02 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 15:44:06 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char a[50] = "Juanma\0feds";
	printf("%s\n",memset(a, '$', 20));
	printf("%s",ft_memset(a, '$', 20));
	return (0);
}
*/
