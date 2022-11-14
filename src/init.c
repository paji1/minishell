/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:09:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/13 22:02:40 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"






/**
 * @brief initialize vars structure
 * 
 * @param vars struct inside main function
 */
int	init(t_vars *vars, char **env)
{
	static char	*op_tab[] = {
	[AND] = "&&",
	[OR] = "||",
	[PIP] = "|",
	[REDIRECT_SO] = ">",
	[REDIRECT_SI] = "<",
	[APPEND] = ">>",
	[HERDOC] = "<<",
	[CMD] = "CMD",
	[ARG] = "ARG",
	[OPTIONS] = "OPTIONS"
	};

	vars->buff = NULL;
	vars->base_name = NULL;
	vars->root = NULL;
	vars->op_tab = op_tab;
	vars->roots = new_stack();
	if (!vars->roots)
		return (1);
	vars->pid_num = 0;
	return (0);	
}
