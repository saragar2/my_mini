/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:19:24 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 15:43:11 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	char c;
	printf("Introduce tu dígito ASCII\n");
	scanf("%c", &c);
	if (isdigit(c) == 0)
		printf("%c is not digit\n", c);
	else
		printf("%c is digit\n", c);
	if (ft_isdigit(c) == 0)
		printf("%c is not digit\n", c);
	else
		printf("%c is digit\n", c);
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(c));
	return (0);
}
*/
