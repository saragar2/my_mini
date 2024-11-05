/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:17:28 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 21:30:31 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char str1[] = "Auanma";
	char str2[] = "Buanmaaaa";
	printf("%d\n", strncmp("c", "a", 6));
	char s1[] = "Auanma";
	char s2[] = "Buanmaaaa";
	printf("%d", ft_strncmp("c", "a", 6));
	return (0);
}
*/
