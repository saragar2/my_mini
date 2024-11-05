/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:28:13 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 15:42:58 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c > 47 && c < 58) || (c > 64 && c < 91)) || (c > 96 && c < 123))
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
	if (isalnum(c) == 0)
		printf("%c is not digit/alpha\n", c);
	else
		printf("%c is digit/alpha\n", c);
	if (ft_isalnum(c) == 0)
		printf("%c is not digit/alpha\n", c);
	else
		printf("%c is digit/alpha\n", c);
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
	return (0);
}
*/
