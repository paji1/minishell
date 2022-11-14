/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:09:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/14 22:39:12 by tel-mouh         ###   ########.fr       */
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
	handle_signal();
	vars->buff = NULL;
	vars->base_name = NULL;
	vars->root = NULL;
	vars->roots = new_stack();
	if (!vars->roots)
		return (1);
	vars->pid_num = 0;
	return (0);	
}
