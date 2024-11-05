/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:50:44 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 17:08:26 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	count = i;
	i = 0;
	while (src[i] != '\0' && i < dstsize - 1 && dstsize != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (count);
}
/*
int	main(void)
{
	char dst[100], src[100] = "i";
	printf("%lu\n", ft_strlcpy(dst, "lorem ipsum dolor sit amet", 0));
	printf("%s", dst);
	return (0);
}
*/
