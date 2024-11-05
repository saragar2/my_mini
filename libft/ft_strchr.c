/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:05:26 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/27 17:22:53 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return (str);
		else
			str++;
	}
	if (*str == (unsigned char)c)
		return (str);
	else
		return (0);
}
/*
int main(void)
{
	char a[100] = "";
	printf("%s\n", ft_strchr(a, 'z'));
	printf("%s\n", a);
	char a2[100] = "";
	printf("%s\n", strchr(a2, 'z'));
	printf("%s", a2);
	return (0);
}
*/
