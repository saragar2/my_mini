/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:27:32 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 21:30:48 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char			*str1;
	const char		*str2;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	str1 = dst;
	str2 = src;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char dest[] = "hare rama hare rama";
	printf("%s\n", dest);
	ft_memcpy((dest + 5), dest, 21);
	printf("%s", dest);
	return (0);
}
*/
