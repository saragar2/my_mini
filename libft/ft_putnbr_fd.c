/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:36:14 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/10/24 15:48:56 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n == 0)
			return ;
		if (n < 0)
		{
			n = n * -1;
			write(fd, "-", 1);
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		num = (n % 10) + '0';
		write(fd, &num, 1);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(10000043, 1);
	return (0);
}
*/
