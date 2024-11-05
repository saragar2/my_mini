/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:53:51 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/12/16 12:58:38 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_printf_type(va_list args, const char *s, int num)
{
	if (s[num] == 'c')
		return (ft_putchar(va_arg(args, int)) - 1);
	if (s[num] == 's')
		return (ft_putstr(va_arg(args, char *)) - 1);
	if (s[num] == 'p')
		return (ft_ptohex(va_arg(args, void *)) - 1);
	if (s[num] == 'd' || s[num] == 'i')
		return (ft_putnbr(va_arg(args, int)) - 1);
	if (s[num] == 'u')
		return (ft_putunsnbr(va_arg(args, unsigned int)) - 1);
	if (s[num] == 'x')
		return (ft_minushex(va_arg(args, int)) - 1);
	if (s[num] == 'X')
		return (ft_mayushex(va_arg(args, int)) - 1);
	return (num);
}

static int	printf_process(va_list args, const char *s, int num)
{
	int	rest;

	rest = 0;
	while (s[num] != '\0')
	{
		if (s[num] == '%')
		{
			num++;
			rest--;
			if (s[num] == '%')
				write(1, &s[num], 1);
			else
				rest = rest + ft_printf_type(args, s, num);
			num++;
		}
		else
		{
			write(1, &s[num], 1);
			num++;
		}
	}
	return (num + rest);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		num;

	num = 0;
	va_start(args, s);
	num = printf_process(args, s, num);
	va_end(args);
	return (num);
}
/*
int	main(void)
{
	int	a = ft_printf("%d\n%u",-42345, 43567);
	ft_printf("\n%d", a);
	return (0);
}
*/
