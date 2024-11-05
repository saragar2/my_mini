/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:26:29 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/12/16 00:18:18 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_length(unsigned long n)
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

static void	ft_hex(char *hexi, unsigned long n, int len)
{
	int		i;
	char	a[20];

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

static int	ft_minushexmod(unsigned long n)
{
	int	len;

	len = ft_length(n);
	ft_hex("0123456789abcdef", n, len);
	return (len + 2);
}

int	ft_ptohex(void *content)
{
	unsigned long	num;

	if (!content)
	{
		write(1, "0x0", 3);
		return (3);
	}
	num = (unsigned long)content;
	write(1, "0x", 2);
	num = ft_minushexmod(num);
	return (num);
}
/*
int	main()
{
	char a[10] = "MONDONGO";
	void	*content;
	content = &a[0];
	ft_ptohex(content);
	return (0);
}
*/
