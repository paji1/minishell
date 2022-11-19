/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_recurs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:42:27 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/18 21:46:16 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exucute(t_node *root, t_vars *vars)
{
	if (root == NULL)
		return ;
	if (handle_exblock(root, vars->env))
		vars->pid_num++;
	if (handle_sub(root, vars))
		return ;
	handle_exop(root, vars->env->env_tab);
	exucute(root->left, vars);
	if (bin_status(root, vars))
		exucute(root->right, vars);
	right_status(root);
}
