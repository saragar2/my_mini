/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:37:59 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/27 18:07:03 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (*(str + i) == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return ((void *)0);
}
/*
int	main(void)
{
	char a[100] = "JuanmaRey";
	printf("%s\n", ft_memchr(a, 'e', 7));
	printf("%s", memchr(a, 'e', 7));
	return (0);
}
*/
