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

int	ft_atoi(char *str, int *flag)
{
	long int	nb;
	int			minus;

	nb = 0;
	minus = 1;
	*flag = 0;
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) == '+' || *(str + 1) == '-' || *(str + 1) == '\0')
			*flag = 1;
		else if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (*str && (*str < 48 || *str > 57))
		*flag = 1;
	if ((nb * minus) > 2147483647 || (nb * minus) < -2147483648)
		*flag = 1;
	return (nb * minus);
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
