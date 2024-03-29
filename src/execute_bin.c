/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:20:56 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/11/19 02:13:11 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wait_for_bin(t_node *node)
{
	if (node->left->node_type == BLOCK)
		waitpid(node->left->token.pid_child, &node->left->token.exit_status, 0);
	node->token.exit_status = node->left->token.exit_status;
	return (node->left->token.exit_status);
}

int	bin_status(t_node *node)
{
	int	status;

	status = 0;
	if (node->token.type == AND || node->token.type == OR)
		status = wait_for_bin(node);
	if (node->token.type == AND)
	{
		if (WEXITSTATUS(status) != 0)
			return (node->token.exit_status = status, 0);
	}
	if (node->token.type == OR)
	{
		if (WEXITSTATUS(status) == 0)
			return (node->token.exit_status = status, 0);
	}
	return (1);
}
