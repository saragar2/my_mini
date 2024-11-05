/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:51:07 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 18:21:37 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*strdest;
	char			*strsrc;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	strdest = (char *)dst;
	strsrc = (char *)src;
	if (strdest > strsrc)
	{
		while (len-- > 0)
			strdest[len] = strsrc[len];
	}
	else
	{
		while (i < len)
		{
			strdest[i] = strsrc[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char str[] = "ab3849201421cdef";
	memmove(str + 8, str, 5);
	printf("%s", str);
	return (0);
}
*/
