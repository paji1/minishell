/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:20:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/04 07:09:23 by akharraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int handle_bin(t_node *node)
{
	if (node->token.type != AND && node->token.type != OR)
		return 0;
}

int wait_for_bin(t_node *node)
{
	if (node->left->node_type == BLOCK)
		waitpid(node->left->token.pid_child, &node->left->token.exit_status, 0);
	node->token.exit_status = node->left->token.exit_status;
	return node->left->token.exit_status;
}

int bin_status(t_node *node, t_vars *vars)
{
	int	status;

	status = 0;
	if (node->token.type == AND || node->token.type == OR)
		status  = wait_for_bin(node);
	if (node->token.type == AND)
	{
		if (WEXITSTATUS(status) != 0)
			return node->token.exit_status = status, 0;
	}
	if (node->token.type == OR)
	{
		if (WEXITSTATUS(status) == 0)
			return node->token.exit_status = status, 0;
	}
	return 1;
}
