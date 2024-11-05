/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:58:37 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/03/05 12:29:48 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*read_next_line(char *buffer_cpy, int fd)
{
	int		byte_read;
	char	*buffer;

	byte_read = 1;
	if (! buffer_cpy)
		buffer_cpy = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !buffer_cpy)
		return (NULL);
	while (byte_read != 0 && (ft_strchr(buffer, '\n') == 0))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1 || (byte_read == 0 && buffer_cpy[0] == 0))
		{
			free(buffer_cpy);
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		buffer_cpy = ft_strjoin(buffer_cpy, buffer);
	}
	free(buffer);
	return (buffer_cpy);
}

char	*getting_line(char *buffer_cpy)
{
	char	*buffer_cpy2;
	int		i;

	i = 0;
	while (buffer_cpy[i] != '\n' && buffer_cpy[i] != '\0')
		i++;
	if (buffer_cpy[i] == '\n')
		buffer_cpy2 = (char *)malloc(sizeof(char) * (i + 2));
	else
		buffer_cpy2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!buffer_cpy2)
		return (NULL);
	i = 0;
	while (buffer_cpy[i] != '\n' && buffer_cpy[i] != '\0')
	{
		buffer_cpy2[i] = buffer_cpy[i];
		i++;
	}
	if (buffer_cpy[i] == '\n')
	{
		buffer_cpy2[i] = '\n';
		i++;
	}
	buffer_cpy2[i] = '\0';
	return (buffer_cpy2);
}

char	*get_next_buffer(char *buffer_cpy, int i, int j)
{
	char	*buffer_cpy3;

	buffer_cpy3 = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!buffer_cpy3)
		return (NULL);
	j = 0;
	while (buffer_cpy[i] != '\0')
	{
		buffer_cpy3[j] = buffer_cpy[i];
		i++;
		j++;
	}
	buffer_cpy3[j] = '\0';
	free(buffer_cpy);
	return (buffer_cpy3);
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	char		*buffer_cpy2;
	static char	*buffer_cpy;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer_cpy = read_next_line(buffer_cpy, fd);
	if (buffer_cpy == NULL || buffer_cpy[0] == 0)
		return (NULL);
	buffer_cpy2 = getting_line(buffer_cpy);
	if (!buffer_cpy2)
		return (NULL);
	i = ft_strlen(buffer_cpy2);
	j = i;
	while (buffer_cpy[j] != '\0')
		j++;
	buffer_cpy = get_next_buffer(buffer_cpy, i, j);
	if (!buffer_cpy)
		return (NULL);
	return (buffer_cpy2);
}
/*
int main(void)
{
    int fd = open("juanma.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
    return (0);
}
*/
