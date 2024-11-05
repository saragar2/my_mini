/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:45:30 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 15:43:15 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char c;
	printf("Introduce tu dígito print\n");
	scanf("%c", &c);
	if (isprint(c) == 0)
		printf("%c is not print\n", c);
	else
		printf("%c is print\n", c);
	if (ft_isprint(c) == 0)
		printf("%c is not print\n", c);
	else
		printf("%c is print\n", c);
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(c));
	return (0);
}
*/
