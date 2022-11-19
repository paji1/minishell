/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_recurs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:42:27 by akharraz          #+#    #+#             */
/*   Updated: 2022/11/19 02:14:37 by tel-mouh         ###   ########.fr       */
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
	handle_exop(root);
	exucute(root->left, vars);
	if (bin_status(root))
		exucute(root->right, vars);
	right_status(root);
}
