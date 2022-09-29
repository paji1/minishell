/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:55:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/20 10:35:56 by akharraz         ###   ########.fr       */
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
# include "types.h"
# include "../src/adam_work/pipe.h"
// --------include readline header--------------
#include <readline/readline.h>
#include <readline/history.h>

// --------include libft header-----------------
# include "../libft/include/libft.h"
// ---------------------------------------------

// --------------free_functions-----------------
void    free_all(t_vars *vars);

// -----------------utils-----------------------
int		is_space(char c);
int		is_special(char *str);
// --------------parsing------------------------
int		parse(t_vars *vars);
void	start_token(char *buff, int i, t_sub *sub);
int		end_token(char *buff, int i, t_sub *sub);
int		handle_last(t_vars *vars, int i, t_sub *sub);
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
void	init(t_vars *vars);
// -------------------type----------------------
int		get_type(char *token);
int		block_op(char *token);

// ---------------node__________________________
t_node	*new_tnode(void);
// ----------------handle_tree------------------
int		handle_token(char *token ,t_vars *vars);
void	put_block(t_node **root, t_node *new);
int		handle_OP(t_vars *vars, t_node *node);
void	above_root(t_node **root, t_node *new);
void	nested(t_node **root, t_node *new);
void	put_redir(t_node **root, t_node *new);
// -------------node ---------------------------
t_node *create_token(t_node *new, char *token);
// ================print========================
void print_tree(t_node *root,t_vars *vars);
// ---------------------------------------------






#endif