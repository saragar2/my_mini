NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
RM = rm -rf



DIR_ENV = env/
SRCS_ENV = env.c get_env.c change_to_env.c
ENV = $(addprefix $(DIR_ENV), $(SRCS_ENV))


DIR_MINISHELL_INIT = minishell_init/
SRCS_MINISHELL_INIT = minishell.c init_input.c signals.c
MINISHELL_INIT = $(addprefix $(DIR_MINISHELL_INIT), $(SRCS_MINISHELL_INIT))


DIR_TOOLS = tools/
SRCS_TOOLS = double_str.c token_list.c del_token.c ft_split_minishell.c join_tokens.c get_comb_of_argv.c ft_split_for_awk.c ft_strtrim_with_free.c
TOOLS = $(addprefix $(DIR_TOOLS), $(SRCS_TOOLS))


DIR_FREE = free/
SRCS_FREE = free.c exit.c
FREE = $(addprefix $(DIR_FREE), $(SRCS_FREE))


DIR_PARSING = parsing/
SRCS_PARSING = input_to_tokens.c token_types.c token_parsing.c parse_basic_redir.c parse_text.c parse_append_heredoc.c
PARSING = $(addprefix $(DIR_PARSING), $(SRCS_PARSING))

DIR_EXECUTE = execute/
SRCS_EXECUTE = init_execution.c execute_command.c
EXECUTE = $(addprefix $(DIR_EXECUTE), $(SRCS_EXECUTE))

DIR_DIRECTORIES_PIPES = directories_pipes/
SRCS_DIRECTORIES_PIPES = get_infile.c get_outfile.c get_pipe.c close_fd.c
DIRECTORIES_PIPES = $(addprefix $(DIR_DIRECTORIES_PIPES), $(SRCS_DIRECTORIES_PIPES))

DIR_BUILTIN = builtin/
SRCS_BUILTIN = builtin_execute.c echo_builtin.c cd_builtin.c pwd_builtin.c exit_builtin.c unset_builtin.c export_builtin.c env_builtin.c
BUILTIN = $(addprefix $(DIR_BUILTIN), $(SRCS_BUILTIN))

SRCS = $(ENV) $(MINISHELL_INIT) $(TOOLS) $(FREE) $(PARSING) $(EXECUTE) $(DIRECTORIES_PIPES) $(BUILTIN)
OBJS = $(SRCS:.c=.o)


INCLUDE = -I include -I libft
LIBRARY = -L libft -lft -lreadline


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Objects created"
	@make -C libft
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBRARY) -o $(NAME)
	@echo "$(NAME) created"


clean:
	@make clean -C libft
	@$(RM) $(OBJS)
	@echo "Objects removed"

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

run: all clean

.PHONY: all clean fclean re run 
