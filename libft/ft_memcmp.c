/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:08:16 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/28 17:04:41 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int			i;
	const unsigned char		*str1;
	const unsigned char		*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str1[] = "Juanma";
	char str2[] = "Juanmaaaa";
	printf("%d\n", memcmp(str2, str1, 10));
	char s1[] = "Juanma";
	char s2[] = "Juanmaaaa";
	printf("%d", ft_memcmp(s2, s1, 10));
	return (0);
}
*/
