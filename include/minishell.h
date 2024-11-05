#ifndef	MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "messages.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <limits.h>
# include <sys/wait.h>

typedef struct s_token
{
	int				type;
	char			*str;
	
	int				infile;
	int				outfile;
	int				heredoc;
	int				append;
	int				cmd;

	struct s_token	*next;
}	t_token;

typedef struct s_minishell
{
	struct s_token	**tokens;
	char			**env;
	int				size_of_env;

	int				exit;
	int				exit_status;
	int				error;

	char			*user_input;

	int				pipes;
	int				wait_pid_status;

	int				before_infile;
	int				infile;
	int				before_outfile;
	int				outfile;
	int				**pipe_fd;
	pid_t			*pid;
}	t_minishell;



// DIRECTORIES_PIPES FUNCTIONS //

int		get_infile(t_minishell *minishell, int infile_fd, int pipe_index);
int		get_outfile(t_minishell *minishell, int outfile_fd, int pipe_index);
void	pipe_create(t_minishell *minishell, int i);
void	create_pipes(t_minishell *minishell);
void	pipe_read_dup(t_minishell *minishell, int i);
void	pipe_write_dup(t_minishell *minishell, int i);
void	close_file_descriptors(t_minishell *minishell);

// ENV FUNCTIONS //

char	*get_line_before_env(char *line, int len);
char	*get_env(char *line, int stay, int i, t_minishell *minishell);
char	*get_line_after_env(char *line, int i);
char	*get_line_after_env_change(char **substring, char *line, int i, int j);
void	ft_free_env_line_array(char **substring);
char	*get_env_name(char *str);
char	*get_value(char *str);
void	add_new_export_env(char *new_str, t_minishell *minishell);
void	change_env_value(char *name, char *value, t_minishell *minishell);

void	set_env_value(char *str, char *value, t_minishell *minishell);
char	*get_env_value(char *str, t_minishell *minishell);
char	**add_env(char *str, t_minishell *minishell);
void	unset_env(char *str, t_minishell *minishell);
void	get_list_of_env(char **environ, t_minishell *minishell);
void	sum_one_to_shlvl(t_minishell *minishell);

// BUILTIN FUNCTIONS //

void	builtin_execute(t_minishell *minishell, char **cmd_argv);
void	echo_builtin(int argc, char **argv, t_minishell *minishell);
void	pwd_builtin(int argc, char **argv, t_minishell *minishell);
void	cd_builtin(int argc, char **argv, t_minishell *minishell);
void	export_builtin(int argc, char **argv, t_minishell *minishell);
void	unset_builtin(int argc, char **argv, t_minishell *minishell);
void	exit_builtin(int argc, char **argv, t_minishell *minishell);
void	env_builtin(int argc, char **argv, t_minishell *minishell);


// EXECUTE FUNCTIONS //

void	init_execution(t_minishell *minishell);
int		builtin_check(char **argv);
char	*get_cmd_in_line(t_token **tokens, int i, int total_pipes);
void	ft_execute_command(t_minishell *minishell, int i, int total_pipes);

// SIGNALS FUNCTIONS //

void	ctrl_c(int signal);
void	ctrl_c_command(int signal);
void	ctlc_heredoc(int signal);
void	ctrl_slash_command(int signal);

// INPUT FUNCTIONS //

int		is_valid_input(char *str);
char	*init_input(t_minishell *minishell);

// PARSING FUNCTIONS //

void	input_to_tokens(t_minishell *minishell);
int		ft_create_token(t_minishell *minishell, int type, int index, int init_of_str);

int		redirection_token(t_minishell *minishell, int i);
int		pipe_token(t_minishell *minishell, int i);
int		quote_token(t_minishell *minishell, int i);
int		text_token(t_minishell *minishell, int i);

void	parse_tokens(t_minishell *minishell);

void	parse_redir_input(t_minishell *minishell, t_token *list);
void	parse_redir_output(t_minishell *minishell, t_token *list);
void	parse_redir_append(t_minishell *minishell, t_token *list);
void	parse_redir_heredoc(t_minishell *minishell, t_token *list);
void	parse_pipe(t_minishell *minishell, t_token *list);
void	parse_text(t_token *list);
void	parse_quotes(t_token *list);

// TOOLS FUNCTIONS //

int		double_str_len(char **double_array);
void	ft_free_double_array(char **double_array);
void	ft_free_double_array_until_length(char **d_array, int len);
void	free_tokens(t_minishell *minishell);

t_token	**ft_create_double_list(void);
t_token	*ft_lstnew_token(int type, char *str);
void	ft_lstadd_token_back(t_token **token_list, t_token *new);
char	*get_first_word(t_token *list);
char	*get_after_first_word(t_token *list, char *first_word);

void	del_token(t_token *to_del, t_token **list);
void	join_tokens(t_token *cmd1, t_token *cmd2, t_token **tokens);

char	**ft_split_minishell(char *str);
char	**ft_split_for_awk(char *line);
char	*ft_strtrim_with_free(char *str, char *trim);
char	*get_comb_of_argv(int argc, char **argv);

// FREE FUNCTIONS //

void	free_pids(pid_t *pid);
void	ft_exit_error(char *str, t_minishell *minishell);
void	ft_exit_no_error(char *str, t_minishell *minishell);
void	free_all(t_minishell *minishell, int is_exit);
void	no_exit_free(char *str1, char *str2, t_minishell *minishell);


#endif