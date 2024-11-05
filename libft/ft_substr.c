/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 21:32:28 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/28 16:43:20 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (str);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
