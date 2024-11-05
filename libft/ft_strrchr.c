/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:43:14 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/10/24 15:13:11 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	while (i >= 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		else
		{
			i--;
			str--;
		}
	}
	return (0);
}
/*
int	main(void)
{
	char a[100] = "Juanmareyrojas";
	printf("%s\n", ft_strrchr(a, 'n'));
	printf("%s\n", a);
	char a2[100] = "Juanmareyrojas";
	printf("%s\n", strrchr(a2, 'n'));
	printf("%s", a2);
	return (0);
}
*/
