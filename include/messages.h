#ifndef MESSAGES_H
# define MESSAGES_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define MALLOC_ERR "Memory allocation error"
# define QUOTES_ERR "Quotes not closed"
# define PARSE_ERR "Error at input parsing"
# define NOT_CMD ": command not found"
 
# define REDIR_HEREDOC 1
# define REDIR_APPEND 2
# define REDIR_INPUT 3
# define REDIR_OUTPUT 4
# define PIPE 5
# define TEXT 6
# define SINGLE_QUOTE 7
# define DOUBLE_QUOTE 8

# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"

# define PATH_MAX 4096

#endif