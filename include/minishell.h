/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:55:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/04 00:53:30 by akharraz         ###   ########.fr       */
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

// --------------parsing------------------------
int parse(t_vars *vars);
// ------------------dir------------------------
char	*getbasename(char *path);
void	getdir(char **base_name);
char	*dub_add(char *str, char *ad);
// -----------------init------------------------
void	init(t_vars *vars);
// ---------------------------------------------





#endif