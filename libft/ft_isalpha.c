/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:18:40 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 15:43:03 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	if (isalpha(c) == 0)
		printf("%c is not alpha\n", c);
	else
		printf("%c is alpha\n", c);
	if (ft_isalpha(c) == 0)
		printf("%c is not alpha\n", c);
	else
		printf("%c is alpha\n", c);
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(c));
	return (0);
}
*/
