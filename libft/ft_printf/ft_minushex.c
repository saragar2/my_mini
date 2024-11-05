/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minushex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:27:23 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/10/03 20:30:25 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_length(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 16 > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static void	ft_hex(char *hexi, unsigned int n, int len)
{
	int		i;
	char	a[12];

	i = len - 1;
	while (n > 0)
	{
		a[i] = (hexi[n % 16]);
		i--;
		n = n / 16;
	}
	i++;
	while (i < len)
	{
		write(1, &a[i], 1);
		i++;
	}
}

int	ft_minushex(unsigned int n)
{
	int	len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = ft_length(n);
	ft_hex("0123456789abcdef", n, len);
	return (len);
}
/*
int	main(void)
{
	ft_minushex(225);
	return (0);
}
*/
