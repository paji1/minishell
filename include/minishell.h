/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:55:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/21 06:47:57 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define __USE_GNU 
# define _GNU_SOURCE

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>

// --------include libft header-----------------
# include "../libft/include/libft.h"
# include "get_next_line.h"
// -------------includePath---------------------
# include "queue.h"
# include "stack.h"
# include "types.h"
# include "execute.h"
# include "builtins.h"
// --------include readline header--------------
# include <readline/readline.h>
# include <readline/history.h>

# include <curses.h>
# include <term.h>
// ---------------------------------------------

# undef tab
// --------------free_functions-----------------
void		free_all(t_vars *vars);
void		free_tree(t_node *root);
void		free_pr(t_node *node);
void		free_tab(char **tab);
// -----------------utils-----------------------
int			is_space(char c);
int			is_special(char *str);
// --------------parsing------------------------
int			parse(t_vars *vars);
void		start_token(char *buff, int i, t_sub *sub);
int			end_token(char *buff, int i, t_sub *sub);
int			handle_last(t_vars *vars, int i, t_sub *sub, t_quote *quote);
int			quote_handle(t_quote *quote, int i, char *buff);
// -------------------lexer --------------------
char		*handle_special(char *buff, t_sub *sub, int *i);
char		*lexer(char *buff, t_sub *sub);
int			accepted(t_node *new);
int			handle_pranteses(t_node *new);
int			handle_empty_cmd(t_node *new);
// ------------------dir------------------------
char		*getbasename(char *path);
size_t		getdir(char **base_name);
char		*dub_add(char *str, char *ad);
// -----------------init------------------------
int			init(t_vars *vars);
// -------------------type----------------------
int			get_type(char *token);
int			block_op(int type);
int			is_sub(t_node *node);
void		above_root(t_node **root, t_node *new);

// ---------------node__________________________
t_node		*new_tnode(void);
// ----------------handle_tree------------------
int			handle_token(char *token, t_vars *vars);
void		put_block(t_node **root, t_node *new);
int			handle_op(t_vars *vars, t_node *node);
int			handle_block(t_vars *vars, t_node *node);
void		above_root(t_node **root, t_node *new);
void		nested(t_node **root, t_node *new);
void		put_redir(t_node **root, t_node *new);
int			is_sub(t_node *node);

// -------------herdoc -------------------------
int			handle_herdoc(t_node *new);
// -------------node ---------------------------
t_node		*create_token(t_node *new, char *token);
// =====	===========print========================
void		print_tree(t_node *root, t_vars *vars);
// ---------------------------------------------
void		exucute(t_node *root, t_vars *vars);
char		**qto_tab(t_node *node, t_env *env);

// =============================================
int			init_env(t_vars *vars, char **env_tab);
void		remove_env_node(t_env *env, char *key);
void		add_to_env_tail(t_env *env, t_env_node *new);
t_env_node	*new_env_node(void);
void		free_node_env(t_env_node *node);
void		free_env(t_env *env);
char		*get_value(t_env *env, char *key);
int			ignore_oldpwd(t_env_node *node, int *sk);
// =============================================
int			split_with_equal(t_env_node *node, char *str);
int			size_env(char **tab);

// =============================================
char		**alloc_to_env(char **tab, t_env *env);
char		**env_lst_to_tab(t_env *env);
int			free_and_allocate(t_env *env);

// =================expader=====================
void		expand_string_toquote(char **str);
void		expand_str(char **str, t_env *env);
char		*allocate_to_value(char **str, size_t start, \
			size_t end, t_env *env);
int			count_lent(char *key);
void		expand_wildcard(char **buff);
void		expand_str_before(char **str, t_env *env);
int			is_delim(char *str, int i);
void		expand_str_herdoc(char **str, t_env *env);
// =============================================

void		hide_ctrl_c(void);
void		restore_ctrl_c(void);

// =============================================
void		handle_history(t_vars *vars);
void		add_history_write(t_vars *vars);
// =============================================
void		ignore_signal(void);
void		handle_signal(void);
void		remove_signal(void);
void		ignore_signal_quit(void);
void		ignore_signal_herdoc(void);

// =============================================

void		print_env_tab(char **tab);
int			create_file(void);
// ==============================================
void		right_status(t_node *node);

extern t_g_exit	g_exit;

#endif