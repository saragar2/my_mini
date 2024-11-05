/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:25:46 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/11/11 11:37:49 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	except(int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		write(1, "-2147483648", 11);
		return (11);
	}
}

static int	count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	num;
	int		i;

	if (n == 0 || n == -2147483648)
		return (except(n));
	else
	{
		i = count(n);
		if (n < 0)
		{
			n = n * -1;
			write(1, "-", 1);
		}
		if (n > 9)
			ft_putnbr(n / 10);
		num = (n % 10) + '0';
		write(1, &num, 1);
		return (i);
	}
}
/*
int	main(void)
{
	int	i;
	int	n = -2145;
	i = ft_putnbr(n);
	printf("%d", i);
	return (0);
}
*/
