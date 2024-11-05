/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:26:57 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/11/11 11:47:35 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putunsnbr(unsigned int n)
{
	char	num;
	int		i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		i = count(n);
		if (n > 9)
			ft_putunsnbr(n / 10);
		num = (n % 10) + '0';
		write(1, &num, 1);
		return (i);
	}
}
/*
int	main(void)
{
	int	i;
	i = ft_putunsnbr(4234212321);
	printf("%d", i);
	return (0);
}
*/
