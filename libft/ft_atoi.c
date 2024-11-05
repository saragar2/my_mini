/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:44:31 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 16:21:08 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	neg;

	num = 0;
	neg = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			neg++;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		num = num * 10;
		num = num + (*str - '0');
		str++;
	}
	if (neg == 1)
		num = num * -1;
	return (num);
}
/*
int	main(void)
{
	char a[100] = "\n\n\n   -46\b9 \n5d6";
	printf("%d\n",ft_atoi(a));
	printf("%d", atoi(a));
	return (0);
}
*/
