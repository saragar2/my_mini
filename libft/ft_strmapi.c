/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:14:28 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/27 18:11:34 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	unsigned int	j;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	while (s[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	j = i;
	i = 0;
	while (i < j)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	ft_toupper(unsigned int i,char c)
{
	i = 0;
	if (c > 96 && c < 123)
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}

int	main(void)
{
	char (*p)(unsigned int, char);
	p = ft_toupper;
	printf("%s", ft_strmapi("", p));
	return (0);
}
*/
