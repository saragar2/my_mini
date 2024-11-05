/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:46:15 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/10/24 14:55:16 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	a_size(char const *s, char c)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			line++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (line);
}

static char	**ft_free(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	return (0);
}

static char	*ft_dup_array(char const *s, char c)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	string = (char *)malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	while (j < i)
	{
		string[j] = s[j];
		j++;
	}
	string[j] = '\0';
	return (string);
}

static char	**a_assign(char const *s, char c, char **str)
{
	int	j;

	j = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			str[j] = ft_dup_array(s, c);
			if (str[j] == NULL)
			{
				ft_free(str, j);
				return (NULL);
			}
			j++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		num_arrays;
	char	**str;

	num_arrays = a_size(s, c);
	str = (char **)malloc(sizeof(char *) * (num_arrays + 1));
	if (!str)
		return (NULL);
	str = a_assign(s, c, str);
	return (str);
}
/*
int	main(void)
{
	int	i = 0;
	char const*	map = "1111111\n1001C01\n1E010P1\n10C0001\n1111111";
	char**	map1;

	map1 = ft_split(map, '\n');
	while (map1[i] != NULL)
	{
			printf("%s\n",map1[i]);
			printf("%zu\n",ft_strlen(map1[i]));
			i++;
	}
	return (0);
}
*/