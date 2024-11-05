/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:32:44 by jrey-roj          #+#    #+#             */
/*   Updated: 2023/09/28 16:26:46 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (*(set + j) != '\0')
	{
		if (*(set + j) == *(s1 + i))
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

int	ft_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (*(set + j) != '\0')
	{
		if (*(set + j) == *(s1 + i))
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (!s1)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set) + 1;
	if (start > end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
/*
static int	ft_strlength(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

static char	*ft_strduplicate(char *s1, int j, int k)
{
	char	*str;
	int		i;
	int		count;

	if (k >= j)
		str = (char *)malloc((k - (j - 1)) * sizeof(char));
	else
		str = (char *)malloc((j - (k - 1)) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (k >= j)
	{
		count = k - j;
		k = 0;
	}
	else
		count = j - k;
	while (s1[k] != '\0' && i < count)
		str[i++] = s1[k++];
	str[i] = '\0';
	return (str);
}

static char	*no_start(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	j = ft_strlength((char *) s1);
	str = ft_strduplicate((char *) s1, j, i);
	if (!str)
		return (NULL);
	return (str);
}

static char	*no_finish(char *s1, char *s2, int j)
{
	char	*str;
	int		i;

	i = (ft_strlength((char *) s1)) - 1;
	if (i >= 0)
	{
		while (s2[j] != '\0')
		{
			if (s1[i] != s2[j] && s2[j] != '\0')
				j++;
			else
			{
				i--;
				j = 0;
			}
		}
	}
	j = 0;
	while (s1[i++] != '\0')
		j++;
	str = ft_strduplicate((char *) s1, j, i);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		j;

	j = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (NULL);
	str = no_start(s1, set);
	if (!str)
		return (NULL);
	if (ft_strlength(str) == 0)
		return (str);
	str = no_finish(str, (char *)set, j);
	if (!str)
		return (NULL);
	return (str);
}
*/
/*
int main(void)
{
    printf("%s", ft_strtrim("", ""));
    return (0);
}
*/
