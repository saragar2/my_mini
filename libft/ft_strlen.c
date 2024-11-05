/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:49:42 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/26 15:46:16 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	const char *s;
	char a[] = "!jfdkaafdda	";
	s = &a[0];
	printf("%zu\n",ft_strlen(s));
	printf("%lu", strlen(s));
}
*/
