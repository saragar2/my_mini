/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:23:11 by saragar2          #+#    #+#             */
/*   Updated: 2024/12/03 20:02:56 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *get_heredoc_line(char *eof)
{
    int pipe_fd[2];
    pid_t pid;
    char *line = NULL;
    char buffer[1024];
    ssize_t bytes_read;

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        return NULL;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return NULL;
    }

    if (pid == 0) // Proceso hijo.
    {
        char *line_to_get;

        signal(SIGINT, ctlc_heredoc); // Configura manejador de SIGINT.
        close(pipe_fd[0]);           // Cierra la lectura del pipe.

        while (1)
        {
            line_to_get = get_next_line(STDIN_FILENO);

            // Si `get_next_line` retorna NULL (EOF o error).
            if (!line_to_get)
            {
                close(pipe_fd[1]); // Cerramos el pipe antes de salir.
                exit(1);
            }

            // Comparamos con el delimitador `eof`.
            if (ft_strncmp(line_to_get, eof, ft_strlen(eof)) != 0 || (ft_strlen(line_to_get) - 1) != ft_strlen(eof))
            {
                write(pipe_fd[1], line_to_get, ft_strlen(line_to_get));
                write(pipe_fd[1], "\n", 1); // Añadir salto de línea.
                free(line_to_get);          // Liberamos la memoria correctamente.
            }
            else
            {
                free(line_to_get); // Liberamos incluso si es `eof`.
                break;
            }
        }

        close(pipe_fd[1]); // Cerramos la escritura del pipe.
        exit(0);           // Terminamos el proceso hijo.
    }
    else // Proceso padre.
    {
        int status;

        close(pipe_fd[1]); // Cierra la escritura del pipe en el padre.

        line = ft_strdup(""); // Inicializamos `line`.

        // Leemos del pipe.
        while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0)
        {
            buffer[bytes_read] = '\0'; // Aseguramos que el buffer sea una cadena válida.
            char *temp = line;
            line = ft_safe_strjoin(line, buffer); // Usamos una función segura para concatenar.
            free(temp);                           // Liberamos la memoria previa solo si `line` no falla.

            if (!line)
            {
                // Si `ft_safe_strjoin` falla, liberamos el pipe y retornamos NULL.
                close(pipe_fd[0]);
                return NULL;
            }
        }

        close(pipe_fd[0]); // Cerramos la lectura del pipe.

        // Esperamos al hijo y verificamos si fue interrumpido.
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
        {
            free(line); // Liberamos si se interrumpió por Ctrl+C.
            return NULL;
        }
    }

    return line;
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
