/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:34:28 by aherrero          #+#    #+#             */
/*   Updated: 2022/06/24 19:18:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <time.h>
# include <stdlib.h>
# include <pthread.h>
# include <termios.h>

typedef struct s_dict_t_struct
{
	char					*key;
	char					*value;
	struct s_dict_t_struct	*next;
}	t_dict;

typedef struct s_data
{
	t_dict					*env;
	t_dict					*commands;
	char					*usr;
	char					*str;
	char					*prompt;
	t_dict					**redirections;
	int						is_redir;
	int						fd_aux;
	int						infile_error;
	int						rediretions_conut;
	int						fd[2];
}	t_data;

int		g_stats;
char	*space_front_to_back(char *c);

t_dict	**dicta_alloc(void);
void	dict_dealloc(t_dict **dict);
void	*get_item(t_dict *dict, char *key);
void	del_item(t_dict **dict, char *key);
t_dict	*dict_new(char *key, char *value);
t_dict	*dict_add_back(t_dict *lst, t_dict *new);
t_dict	*dict_add_back_repeat(t_dict *lst, t_dict *new);
t_dict	*dict_add_front(t_dict *lst, t_dict *new);
char	*get_dict_value(t_dict *dict, char	*key);
t_dict	*del_one(t_dict *dict, char	*key);
void	delete_all(t_dict *dict);
void	del_one_aux(t_dict *temp, t_dict *q, char *key);

char	*remove_spaces(char	*str);
char	*expand(t_data *data, char *str);
char	*ft_readline(t_data *data);
char	*replace_redirections(char *str);
char	*delete_redirections(char *str);

void	print_dict(t_dict *env);
t_dict	*create_env(char **str);
t_dict	*ft_export(t_data *data);
t_dict	*ft_unset(t_dict *env, char **str);
t_data	*_cd(char *str, char *usr, t_data *data);
void	ft_pwd(void);
void	ft_echo(t_data *data);
char	*syntax_redirections(char *str);
char	*check_quotes(char *str);
char	*get_path(char *_path, char *command);
void	print_error(t_data *data, char *path);
char	*minishell_loop(t_data *data, char *str);

void	export_aux_continue(char *value,
			char *key, char **key_value, t_data *data);

t_dict	*ft_sort(char **c);
char	*sort_aux(char *str, char **temp, int *i);
void	ft_history(char *str);
t_dict	*ft_pipe_parse(char *str);
void	ft_execve(t_data *data);
void	ft_signals(void);
void	continue_signal(void);

int		check_syntax(t_dict *commands);
t_data	*get_redirections(t_data *data, char *str);
t_data	*redirections(t_data *data);
t_data	*builtings(t_data *data, char *str);
void	ft_exit(char *str, t_data *data);
int		ft_exit_end(t_data *data, int i, int *space);
char	*here_doc(t_data data, t_dict *temp);
void	expand_execve(int status);

void	free_mem(t_data *data, char *str);

int		check_outfile(t_data *data, int j);
char	*check_infile(t_data *data, int j);
int		redirections_fd_aux(t_data *data, int temp_out);
char	*heredoc(t_data *data, t_dict *temp);
char	*ft_readline_heredoc(t_data *data);
void	redirections_aux(t_data *data, int fd_in, int temp_in, int temp_out);
t_data	*redirections_fd(t_data *data, int fd_in, int temp_out, int j);
char	*get_redirections_loop(t_data *data, char *str, int *j, int *count);
void	add_to_dict_aux(char *str, char *value);
t_dict	**add_to_dict(t_dict **result, int j, int count, char *str);

char	**continue_execve(t_data *data, char **temp, char **argv, char *key);
void	_execve_print(t_data *data);
char	*modify_str(char *str, int j);
char	aux(char p, int n);
int		aux_aux(int n, char *c, char *str, int j);
char	**join_env(t_dict *d_env);

/*  Expand functions*/

char	*continue_expand_three(char *str, char *tmp, t_data *data, int i);
char	*continue_expand_two(char *str, int i, char *tmp, t_data *data);
char	*continue_expand_for(char *str, int i, char *tmp, char *var);
char	continue_expand(char c, int i, char *str);
char	*space_front_to_back_aux(char *c, int i, int j, int fill);
char	remove_quotes_aux(char *str, char *temp, int *i, int j);
char	remove_quotes_get_c(char *str, int *n, char c, int i);
t_dict	*ft_pipe_parse_add(char *str, int *last, t_dict *commands, int i);
t_dict	*ft_pipe_parse_end(char *str, int last, t_dict *commands, int i);
t_dict	*add_command(char *line, t_dict *command);
char	*remove_spaces_aux(char	*str, int i);
char	*remove_spaces_aux_aux(char *str, int jj);
char	*remove_spaces_aux_temp(char *str, int i);

char	*get_arguments(char	*str);
char	*remove_spaces(char	*str);
t_dict	*ft_pipe_parse(char *str);
char	*check_quotes(char *str);
char	*remove_quotes(char *str);
char	*get_builting(char	*str);

void	free_split(char *temp);
void	free_split_double(char **temp);
char	*aux_get_path(char **paths, char *path);
void	free_data_readline_two(t_data *data);
void	free_data_readline(t_data *data);
char	*aux_replace_redirections(char *str, char *temp, char c, int n);
int		replace_aux(int n, char *c, char *str, int j);
char	replace_char(char *str, int i, int n);

void	end_redirections_aux(int temp_in, int temp_out, int pid, int status);
char	*continue_expand_three_aux(char *str,
			char *aux, int i, char *tmp);
int		get_j(char *str, int j);
char	*pipe_errors_aux(char *str);

/* remove aux quotes*/
int		aux_quotes(char *str);
char	*aux_quotes_two(char *temp, char *str);
#endif
