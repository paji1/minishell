/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:09:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/09/05 19:17:38 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief initialize vars structure
 * 
 * @param vars struct inside main function
 */
void	init(t_vars *vars)
{
	vars->buff = NULL;
	vars->base_name = NULL;
	vars->node = NULL;
}