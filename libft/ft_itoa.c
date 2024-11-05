/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:17:40 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/10/24 14:54:49 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*zero(void)
{
	char	*num;

	num = (char *)malloc(sizeof(char) * 2);
	if (!num)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

static char	*exceptions(int n)
{
	int		i;
	char	*num;

	i = 9;
	if (n == 0)
	{
		num = zero();
		return (num);
	}
	else
	{
		num = (char *)malloc(sizeof(char) * 12);
		if (!num)
			return (NULL);
		num[11] = '\0';
		num[10] = '8';
		n = n / -10;
		num[0] = '-';
		while (i > 0)
		{
			num[i--] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (num);
}

static char	*i_to_a(int n, int i, int count)
{
	char	*num;

	if (n < 0)
	{
		n = n * -1;
		num = (char *)malloc(sizeof(char) * (count + 2));
		if (!num)
			return (NULL);
		num[0] = '-';
		count++;
	}
	else
	{
		num = (char *)malloc(sizeof(char) * (count + 1));
		if (!num)
			return (NULL);
	}
	num[count] = '\0';
	i = count - 1;
	while (n > 0)
	{
		num[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		count;
	int		i;

	i = 0;
	count = ft_len(n);
	if (n == 0 || n == -2147483648)
	{
		num = exceptions(n);
		return (num);
	}
	num = i_to_a(n, i, count);
	return (num);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(2147483647));
	return (0);
}
*/
