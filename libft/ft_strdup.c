/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:51:22 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/28 16:38:10 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*stay;
	int		i;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (str);
	stay = str;
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (stay);
}
/*
int	main(void)
{
	const char	a[] = "Juanma";
	const char	b[] = "Juanma";
	printf("%s\n", strdup(a));
	printf("%s", ft_strdup(b));
	return (0);
}
*/
