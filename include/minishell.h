/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:55:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/05 17:40:25 by tel-mouh         ###   ########.fr       */
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
# include "queue.h"
# include "types.h"
// --------include readline header--------------
#include <readline/readline.h>
#include <readline/history.h>

// --------include libft header-----------------
# include "../libft/include/libft.h"
// ---------------------------------------------

// --------------free_functions-----------------
void    free_all(t_vars *vars);
// --------------depth_first_values-------------


// -----------------utils-----------------------
int		is_space(char c);
int		is_special(char *str);
// --------------parsing------------------------
int		parse(t_vars *vars);
void	start_token(char *buff, int i, t_sub *sub);
int		end_token(char *buff, int i, t_sub *sub);
void	handle_last(char *buff, int i, t_sub *sub);
char    *lexer(char *buff, t_sub *sub);
int		quote_handle(t_quote *quote, int i, char *buff);
// ------------------dir------------------------
char	*getbasename(char *path);
void	getdir(char **base_name);
char	*dub_add(char *str, char *ad);
// -----------------init------------------------
void	init(t_vars *vars);
// ---------------------------------------------





#endif