/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:55:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/08/16 05:44:50 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
// -------------includePath---------------------
# include "types.h"
# include "stack.h"
// --------include readline header--------------
#include <readline/readline.h>
#include <readline/history.h>

// --------include libft header-----------------
# include "../libft/include/libft.h"
// ---------------------------------------------
void	insert(t_node **node, t_node *new);
int		contain(t_node **node, int data);
t_node	*new_node(int data, int type);
// --------------free_functions-----------------
void	free_tree(t_node **node);
void	free_split(char **s);
void	free_all(t_vars *vars);
// --------------depth_first_values-------------
void	calculate(t_node *node);
void	iter_print(t_node *node);
// --------------breadth_first_values-----------
void	brefirstrev(t_node *node);
// -----------------utils-----------------------
int		check_types(char *s);
// -------------insertion-methods---------------
void	new_head(t_node **node, char token, int num_right);
void	nested(t_node **node, int token, int right);
// --------------parsing------------------------
void parse(char **s, t_node **node);
// ------------------dir------------------------
char	*getbasename(char *path);
void	getdir(char **base_name);
char	*dub_add(char *str, char *ad);
// -----------------init------------------------
void	init(t_vars *vars);
// ---------------------------------------------





#endif