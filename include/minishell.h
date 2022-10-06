/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:55:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/10/05 17:06:34 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
// -------------includePath---------------------
# include "queue.h"
# include "stack.h"
# include "types.h"
// --------include readline header--------------
#include <readline/readline.h>
#include <readline/history.h>

// --------include libft header-----------------
# include "../libft/include/libft.h"
// ---------------------------------------------

// --------------free_functions-----------------
void    free_all(t_vars *vars);
void	free_tree(t_node *root);
void	free_pr(t_node *node);
// -----------------utils-----------------------
int		is_space(char c);
int		is_special(char *str);
// --------------parsing------------------------
int		parse(t_vars *vars);
void	start_token(char *buff, int i, t_sub *sub);
int		end_token(char *buff, int i, t_sub *sub);
int		handle_last(t_vars *vars, int i, t_sub *sub, t_quote *quote);
int		quote_handle(t_quote *quote, int i, char *buff);
// -------------------lexer --------------------
char    *handle_special(char *buff, t_sub *sub, int *i);
char    *lexer(char *buff, t_sub *sub);
int		accepted(t_node *new);
// ------------------dir------------------------
char	*getbasename(char *path);
size_t	getdir(char **base_name);
char	*dub_add(char *str, char *ad);
// -----------------init------------------------
void	init(t_vars *vars, char **env);
// -------------------type----------------------
int		get_type(char *token);
int		block_op(int type);
int		is_sub(t_node *node);

// ---------------node__________________________
t_node	*new_tnode(void);
// ----------------handle_tree------------------
int		handle_token(char *token ,t_vars *vars);
void	put_block(t_node **root, t_node *new);
int		handle_OP(t_vars *vars, t_node *node);
int		handle_block(t_vars *vars, t_node *node);
void	above_root(t_node **root, t_node *new);
void	nested(t_node **root, t_node *new);
void	put_redir(t_node **root, t_node *new);
// -------------herdoc -------------------------
int		handle_herdoc(t_node *new);
// -------------node ---------------------------
t_node	*create_token(t_node *new, char *token);
// ================print========================
void	print_tree(t_node *root,t_vars *vars);
// ---------------------------------------------
void	exucute(t_node *root,t_vars *vars);
char	**qto_tab(t_node *node);
int	check_cmd(t_node *node, char **env, char **path);



#endif