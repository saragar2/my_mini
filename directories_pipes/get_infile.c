/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:23:11 by saragar2          #+#    #+#             */
/*   Updated: 2024/12/18 15:11:14 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_heredoc_line(char *eof)
{
	t_heredoc	g;
	
	g.line = NULL;
	if (pipe(g.pipe_fd) == -1)
		return (perror("pipe"), NULL);
	g.pid = fork();
	if (g.pid == -1)
		return (perror("fork"), NULL);
	if (g.pid == 0) // Proceso hijo.
	{
		signal(SIGINT, ctlc_heredoc); // Configura manejador de SIGINT.
		close(g.pipe_fd[0]);           // Cierra la lectura del pipe.
		while (1)
		{
			g.line_to_get = get_next_line(STDIN_FILENO);
			if (!g.line_to_get)
			{
				close(g.pipe_fd[1]); // Cerramos el pipe antes de salir.
				exit(1);
			}
			if (ft_strncmp(g.line_to_get, eof, ft_strlen(eof)) != 0 || (ft_strlen(g.line_to_get) - 1) != ft_strlen(eof))
			{
				write(g.pipe_fd[1], g.line_to_get, ft_strlen(g.line_to_get));
				write(g.pipe_fd[1], "\n", 1); // Añadir salto de línea.
				free(g.line_to_get);          // Liberamos la memoria correctamente.
			}
			else
			{
				free(g.line_to_get); // Liberamos incluso si es `eof`.
				break;
			}
		}
		close(g.pipe_fd[1]); // Cerramos la escritura del pipe.
		exit(0);           // Terminamos el proceso hijo.
	}
	else // Proceso padre.
	{
		close(g.pipe_fd[1]); // Cierra la escritura del pipe en el padre.
		g.line = ft_strdup(""); // Inicializamos `line`.
		while ((g.bytes_read = read(g.pipe_fd[0], g.buffer, sizeof(g.buffer) - 1)) > 0)
		{
			g.buffer[g.bytes_read] = '\0'; // Aseguramos que el buffer sea una cadena válida.
			g.temp = g.line;
			g.line = ft_safe_strjoin(g.line, g.buffer); // Usamos una función segura para concatenar.
			free(g.temp);                           // Liberamos la memoria previa solo si `line` no falla.
			if (!g.line)
				return (close(g.pipe_fd[0]), NULL);
		}
		close(g.pipe_fd[0]); // Cerramos la lectura del pipe.
		waitpid(g.pid, &g.status, 0);
		if (WIFSIGNALED(g.status) && WTERMSIG(g.status) == SIGINT)
			return (free(g.line), NULL);
	}
	return (g.line);
}

int	get_heredoc_fd(t_token *list)
{
	int		fd[2];
	char	*here_doc_line;

	if (pipe(fd) < 0)
		return (0);
	else
	{
		here_doc_line = get_heredoc_line(list->str);
		write(fd[1], here_doc_line, ft_strlen(here_doc_line));
		close(fd[1]);
		free(here_doc_line);
		return (fd[0]);
	}
}

int	get_infile_fd(t_token *list)
{
	int	infile_fd;

	infile_fd = open(list->str, O_RDONLY);
	if (infile_fd < 0)
	{
		ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(list->str, 2);
	}
	return (infile_fd);
}

int	get_infile(t_minishell *minishell, int infile_fd, int pipe_index)
{
	t_token	*list;

	list = *minishell->tokens;
	while ((minishell->pipes) - pipe_index < minishell->pipes)
	{
		while (list && list->type != PIPE)
			list = list->next;
		list = list->next;
		pipe_index--;
	}
	while (list && list->type != PIPE)
	{
		if (list->infile == 1 || list->heredoc == 1)
		{
			if (infile_fd != 0)
				close(infile_fd);
		}
		if (list->infile == 1)
			infile_fd = get_infile_fd(list);
		else if (list->heredoc == 1)
			infile_fd = get_heredoc_fd(list);
		list = list->next;
		if (infile_fd < 0)
			return (infile_fd);
	}
	return (infile_fd);
}
