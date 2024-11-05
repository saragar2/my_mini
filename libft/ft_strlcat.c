/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 01:13:41 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 22:20:03 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static unsigned int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	cnt1;
	unsigned int	cnt2;
	unsigned int	res;
	unsigned int	cont;

	cont = ft_strlength(dst);
	i = 0;
	cnt1 = 0;
	cnt2 = 0;
	while (src[cnt1] != '\0')
		cnt1++;
	if (dstsize <= cont)
		return (cnt1 + dstsize);
	while (dst[cnt2] != '\0')
		cnt2++;
	res = cnt1 + cnt2;
	while (src[i] != '\0' && i < dstsize - 1 && dstsize - 1 > cnt2)
		dst[cnt2++] = src[i++];
	dst[cnt2] = '\0';
	if (dstsize + cnt1 >= res)
		return (res);
	return (dstsize + cnt1);
}
*/
static unsigned int	ft_strlength(char *dst, const char *src, size_t dstsize)
{
	unsigned int	count_dest;
	unsigned int	count_src;
	unsigned int	i;

	count_dest = 0;
	count_src = 0;
	i = 0;
	while (src[i] != '\0')
	{
		count_src++;
		i++;
	}
	i = 0;
	while (dst[i] != '\0' && count_dest < dstsize)
	{
		count_dest++;
		i++;
	}
	i = 0;
	return (count_src + count_dest);
}

size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	suma;

	suma = ft_strlength(dst, src, dstsize);
	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	if (dstsize > i)
	{
		while (src[j] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	return (suma);
}
/*
int	main(void)
{
    char dest[30]; memset(dest, 0, 30);
    char *src = "AAAAAAAAA";
    dest[0] = 'B';
    printf("%lu",ft_strlcat(dest, src,-1));
    printf("%s",memset(dest, 'C', 15));
	return (0);
}
*/
