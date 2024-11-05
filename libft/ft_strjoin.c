/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:12:54 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/27 00:15:06 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlength(char const *str, int count)
{
	while (str[count] != '\0')
		count++;
	if (str[0] == '\0')
		return (0);
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		count;

	if (!s2)
		return ((char *)(s1));
	i = 0;
	count = ft_strlength(s1, i) + ft_strlength(s2, i);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	count = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
		count++;
	}
	i = 0;
	while (s2[i] != '\0')
		str[count++] = s2[i++];
	str[count] = '\0';
	free((char *)s1);
	return (str);
}
/*
int	main(void)
{
	printf("%s",ft_strjoin("Juan\0ma", "Rey Rojas"));
	return (0);
}
*/
