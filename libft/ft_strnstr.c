/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:58:02 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/28 17:11:06 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char		*str;
	const char		*find;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	str = haystack;
	find = needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(str + i) != '\0' && i < len)
	{
		haystack = (str + i);
		while (*(str + i) == *(find + j) && i++ < len)
		{
			if (*(find + j + 1) == '\0')
				return ((char *)haystack);
			j++;
		}
		i = i - j + 1;
		j = 0;
		str = haystack - i + 1;
	}
	return (NULL);
}
/*
int	main(void)
{
	char str1[] = "nem";
	char str2[] = "";
	printf("%s\n", strnstr(str2, str1, 8));
	char s1[] = "nem";
	char s2[] = "";
	printf("%s", ft_strnstr(s2, s1, 8));
	return (0);
}
*/
